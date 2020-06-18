using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using Faza2.Domain;
using Faza2.Observers;
using Faza2.Service;

namespace Faza2.Windows
{
    public partial class ManagerApp : Form, Observable
    {
        public class MultiFormContext : ApplicationContext
        {
            private int openForms;
            public MultiFormContext(params Form[] forms)
            {
                openForms = forms.Length;

                foreach (var form in forms)
                {
                    form.FormClosed += (s, args) =>
                    {
                        if (Interlocked.Decrement(ref openForms) == 0)
                            ExitThread();
                    };

                    form.Show();
                }
            }
        }

        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        private ServiceManager servManager;

        private ServiceTerminal servTerminal;

        private List<TerminalApp> list;

        private List<Piesa> piesaList;
        public ManagerApp()
        {
            InitializeComponent();
            loadData();
        }

        private void loadData()
        {
            try
            {
                servManager = new ServiceManager();

                piesaList = servManager.findPiesaByTeatruId(servManager.findTeatruByNume("I. L. Caragiale").id);

                foreach(Piesa piesa in piesaList)
                {
                    piesaBox.Items.Add(piesa.nume);
                }

                this.servTerminal = new ServiceTerminal();

                this.list = new List<TerminalApp>();

                spectatorTable.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

                foreach (DataGridViewColumn column in spectatorTable.Columns)
                {
                    column.ReadOnly = true;
                }

                locuriTable.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

                foreach (DataGridViewColumn column in locuriTable.Columns)
                {
                    column.ReadOnly = true;
                }

                servTerminal.addObservable(this);

                reloadTable();
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void loadEmptyLocuriTable()
        {
            DataTable source = new DataTable();

            source.Columns.Add("Pozitie", typeof(string));
            source.Columns.Add("Pret", typeof(int));
            source.Columns.Add("Stare", typeof(string));

            locuriTable.DataSource = source;
        }

        private void reloadTable()
        {
            try
            {
                DataTable source = new DataTable();

                source.Columns.Add("Nume", typeof(string));
                source.Columns.Add("Telefon", typeof(string));
                source.Columns.Add("Email", typeof(string));

                List<Spectator> list = servTerminal.findAllSpectator();

                foreach (Spectator spectator in servTerminal.findAllSpectator())
                    source.Rows.Add(spectator.nume, spectator.telefon, spectator.email);

                spectatorTable.DataSource = source;
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            try
            {
                string piesaNume = piesaBox.Text;

                if (piesaNume == "")
                {
                    MessageBox.Show("Piesa nu a fost aleasa");
                    throw new Exception("Piesa nu a fost aleasa !");
                }

                for(int i = 0; i < 4; ++i)
                {
                    TerminalApp ta = new TerminalApp(piesaNume, servTerminal);

                    list.Add(ta);
                }

                closeBtn.Enabled = false;

                Application.Run(new MultiFormContext(list.ElementAt(0), list.ElementAt(1), list.ElementAt(2), list.ElementAt(3)));
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void stopButton_Click(object sender, EventArgs e)
        {
            try
            {
                List<Loc> locuri = servTerminal.findAllLoc();

                List<string> listPozitii = new List<string>();

                foreach(Loc loc in locuri)
                {
                    if (loc.liber == false)
                        listPozitii.Add(loc.pozitie);
                }

                servTerminal.changeStateLoc(listPozitii);
                servTerminal.deleteAllSpectator();
                servTerminal.deleteAllRezervare();

                foreach(TerminalApp ta in list)
                {
                    ta.close();
                }

                list.Clear();

                closeBtn.Enabled = true;

                reloadTable();
                loadEmptyLocuriTable();
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void closeBtn_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void anuleazaBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string nume = spectatorTable.Rows[spectatorTable.SelectedRows[0].Index].Cells[0].Value.ToString();
                string telefon = spectatorTable.Rows[spectatorTable.SelectedRows[0].Index].Cells[1].Value.ToString();
                string email = spectatorTable.Rows[spectatorTable.SelectedRows[0].Index].Cells[2].Value.ToString();

                Spectator spectator = servTerminal.findSpectatorByData(nume, telefon, email);

                List<Rezervare> rezervari = servTerminal.findRezervareByIdSpectator(spectator.id);

                List<string> locuri = new List<string>();

                foreach (Rezervare rezervare in rezervari)
                {
                    string loc = servTerminal.findLocById(rezervare.locId).pozitie;

                    locuri.Add(loc);
                }

                servTerminal.deleteSpectatorNumeSpectator(spectator.nume, spectator.telefon, spectator.email);
                servTerminal.deleteRezervareBySpectator(spectator);
                servTerminal.changeStateLoc(locuri);

                reloadTable();
                notifyObserver();

                if(spectatorTable.SelectedRows.Count == 0)
                    loadEmptyLocuriTable();
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public void notifyObserver()
        {
            servTerminal.notifyObservables();
        }

        public void getNotified()
        {
            reloadTable();
        }

        public void close()
        {
            Close();
        }

        private void reloadLocuri(string nume, string telefon, string email)
        {
            try
            {
                Spectator spectator = servTerminal.findSpectatorByData(nume, telefon, email);

                List<Rezervare> rezervari = servTerminal.findRezervareByIdSpectator(spectator.id);

                List<Loc> locuri = new List<Loc>();

                foreach(Rezervare rezervare in rezervari)
                {
                    Loc loc = servTerminal.findLocById(rezervare.locId);

                    locuri.Add(loc);
                }

                DataTable source = new DataTable();

                source.Columns.Add("Pozitie", typeof(string));
                source.Columns.Add("Pret", typeof(int));
                source.Columns.Add("Stare", typeof(string));

                foreach(Loc loc in locuri)
                {
                    string stare = "Ocupat";

                    bool val = loc.liber;

                    if (val == true)
                        stare = "Liber";

                    source.Rows.Add(loc.pozitie, loc.pret, stare);
                }

                locuriTable.DataSource = source;
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void spectatorTable_SelectionChanged(object sender, EventArgs e)
        {
            try
            {
                string nume = spectatorTable.Rows[spectatorTable.SelectedRows[0].Index].Cells[0].Value.ToString();
                string telefon = spectatorTable.Rows[spectatorTable.SelectedRows[0].Index].Cells[1].Value.ToString();
                string email = spectatorTable.Rows[spectatorTable.SelectedRows[0].Index].Cells[2].Value.ToString();

                reloadLocuri(nume, telefon, email);
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void spectatorTable_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void ManagerApp_Load(object sender, EventArgs e)
        {

        }
    }
}
