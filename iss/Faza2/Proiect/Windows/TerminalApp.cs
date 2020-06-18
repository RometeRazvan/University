using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Faza2.Domain;
using Faza2.Observers;
using Faza2.Service;

namespace Faza2.Windows
{
    public partial class TerminalApp : Form, Observable
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        private ServiceTerminal servTerminal;

        private Piesa piesa;

        bool modifyState = false;

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
        public TerminalApp(string numePiesa, ServiceTerminal servTerminal)
        {
            InitializeComponent();

            loadData(numePiesa, servTerminal);
        }

        private void loadData(string numePiesa, ServiceTerminal servTerminal)
        {
            try
            {
                /*numeText.Text = "Romete Razvan";
                telefonText.Text = "072517286";
                emailText.Text = "r.r@yahoo.com";*/

                this.servTerminal = servTerminal;

                reloadTable();

                servTerminal.addObservable(this);

                foreach (DataGridViewColumn column in locTable.Columns)
                {
                    column.ReadOnly = true;
                }

                this.piesa = servTerminal.findPiesaByNume(numePiesa);

                locTable.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

                titluOperLabel.Text = "Piesa de astazi este: " + piesa.nume;
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void reloadTable()
        {
            try
            {
                DataTable dataTable = new DataTable();

                dataTable.Columns.Add("Pozitie", typeof(string));
                dataTable.Columns.Add("Pret", typeof(int));
                dataTable.Columns.Add("Stare", typeof(string));

                foreach (Loc loc in servTerminal.findAllLoc())
                {
                    string val = "Ocupat";

                    if (loc.liber == true)
                        val = "Liber";

                    dataTable.Rows.Add(loc.pozitie, loc.pret, val);
                }

                locTable.DataSource = dataTable;
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void rezervaBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string nume = numeText.Text;
                string telefon = telefonText.Text;
                string email = emailText.Text;

                List<string> locuri = new List<string>();

                foreach (DataGridViewRow row in locTable.SelectedRows)
                {
                    string pozitie = row.Cells[0].Value.ToString();
                    string stare = row.Cells[2].Value.ToString();

                    if (stare == "Ocupat")
                    {
                        showMessage("Minim un loc este deja ocupat");
                        throw new Exception("MInim un loc este deja ocupat !!!");
                    }

                    locuri.Add(pozitie);
                }

                Spectator spectator = new Spectator();

                spectator.id = Guid.NewGuid();
                spectator.nume = nume;
                spectator.telefon = telefon;
                spectator.email = email;

                List<Rezervare> rezervari = new List<Rezervare>();

                foreach (string str in locuri)
                {
                    Loc loc = servTerminal.findLocByPozitie(str);

                    Rezervare rezervare = new Rezervare();

                    rezervare.id = Guid.NewGuid();
                    rezervare.piesaId = piesa.id;
                    rezervare.spectatorId = spectator.id;
                    rezervare.locId = loc.id;

                    rezervari.Add(rezervare);
                }

                try
                {
                    servTerminal.addSpectator(spectator);
                }
                catch(Exception ex)
                {
                    MessageBox.Show(ex.Message);

                    throw new Exception("Date invalide");
                }

                servTerminal.changeStateLoc(locuri);
                servTerminal.addRezervare(rezervari);

                reloadTable();

                notifyObserver();

                //clearAllText();

            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void showMessage(string text)
        {
            try
            {
                MessageBox.Show(text);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void anuleazaBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string nume = numeText.Text;
                string telefon = telefonText.Text;
                string email = emailText.Text;

                Spectator spectator = servTerminal.findSpectatorByData(nume, telefon, email);

                List<Rezervare> rezervari = servTerminal.findRezervareByIdSpectator(spectator.id);
                //Console.WriteLine(rezervari.Count);
                List<string> locuri = new List<string>();

                foreach (Rezervare rezervare in rezervari)
                {
                    //Console.WriteLine(servTerminal.findLocById(rezervare.locId).pozitie);
                    locuri.Add(servTerminal.findLocById(rezervare.locId).pozitie);
                }

                servTerminal.changeStateLoc(locuri);
                servTerminal.deleteRezervareBySpectator(spectator);
                servTerminal.deleteSpectatorNumeSpectator(spectator.nume, spectator.telefon, spectator.email);

                reloadTable();

                notifyObserver();

                //clearAllText();
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void blockAllExceptModify()
        {
            rezervaBtn.Enabled = false;
            anuleazaBtn.Enabled = false;

            numeText.Enabled = false;
            telefonText.Enabled = false;
            emailText.Enabled = false;
        }

        private void unlockAllExceptModify()
        {
            rezervaBtn.Enabled = true;
            anuleazaBtn.Enabled = true;

            numeText.Enabled = true;
            telefonText.Enabled = true;
            emailText.Enabled = true;
        }

        private void modificaBtn_Click(object sender, EventArgs e)
        {
            try
            {
                if (!modifyState)
                {
                    blockAllExceptModify();

                    string nume = numeText.Text;
                    string telefon = telefonText.Text;
                    string email = emailText.Text;

                    Spectator spectator = servTerminal.findSpectatorByData(nume, telefon, email);

                    List<Rezervare> rezervari = servTerminal.findRezervareByIdSpectator(spectator.id);

                    List<string> locuri = new List<string>();

                    foreach(DataGridViewRow row in locTable.Rows)
                    {
                        try
                        {
                            string pozitie = row.Cells[0].Value.ToString();

                            row.Selected = false;

                            Loc loc = servTerminal.findLocByPozitie(pozitie);

                            foreach(Rezervare rezervare in rezervari)
                            {
                                if (rezervare.locId == loc.id)
                                    row.Selected = true;
                            }
                        }
                        catch(Exception ex)
                        {
                            logger.Error(ex.Message);
                        }
                    }

                    this.modifyState = true;
                }
                else
                {
                    List<string> locuri = new List<string>();

                    foreach(DataGridViewRow row in locTable.SelectedRows)
                    {
                        locuri.Add(row.Cells[0].Value.ToString());
                    }

                    modifyFirstStage();

                    foreach (DataGridViewRow row in locTable.Rows)
                    {
                        try
                        {
                            string pozitie = row.Cells[0].Value.ToString();

                            row.Selected = false;

                            foreach (string poz in locuri)
                            {
                                if (poz == pozitie)
                                    row.Selected = true;
                            }
                        }
                        catch (Exception ex)
                        {
                            logger.Error(ex.Message);
                        }
                    }

                    mofifySecondStage();

                    modifyState = false;

                    unlockAllExceptModify();

                    notifyObserver();

                    //clearAllText();
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void modifyFirstStage()
        {
            try
            {
                string nume = numeText.Text;
                string telefon = telefonText.Text;
                string email = emailText.Text;

                Spectator spectator = servTerminal.findSpectatorByData(nume, telefon, email);

                List<Rezervare> rezervari = servTerminal.findRezervareByIdSpectator(spectator.id);
                //Console.WriteLine(rezervari.Count);
                List<string> locuri = new List<string>();

                foreach (Rezervare rezervare in rezervari)
                {
                    //Console.WriteLine(servTerminal.findLocById(rezervare.locId).pozitie);
                    locuri.Add(servTerminal.findLocById(rezervare.locId).pozitie);
                }

                servTerminal.changeStateLoc(locuri);
                servTerminal.deleteRezervareBySpectator(spectator);
                servTerminal.deleteSpectatorNumeSpectator(spectator.nume, spectator.telefon, spectator.email);

                reloadTable();
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }
    
        private void mofifySecondStage()
        {
            try
            {
                string nume = numeText.Text;
                string telefon = telefonText.Text;
                string email = emailText.Text;

                List<string> locuri = new List<string>();

                foreach (DataGridViewRow row in locTable.SelectedRows)
                {
                    string pozitie = row.Cells[0].Value.ToString();
                    string stare = row.Cells[2].Value.ToString();

                    if (stare == "Ocupat")
                    {
                        showMessage("Minim un loc este deja ocupat");
                        throw new Exception("MInim un loc este deja ocupat !!!");
                    }

                    locuri.Add(pozitie);
                }

                Spectator spectator = new Spectator();

                spectator.id = Guid.NewGuid();
                spectator.nume = nume;
                spectator.telefon = telefon;
                spectator.email = email;

                List<Rezervare> rezervari = new List<Rezervare>();

                foreach (string str in locuri)
                {
                    Loc loc = servTerminal.findLocByPozitie(str);

                    Rezervare rezervare = new Rezervare();

                    rezervare.id = Guid.NewGuid();
                    rezervare.piesaId = piesa.id;
                    rezervare.spectatorId = spectator.id;
                    rezervare.locId = loc.id;

                    rezervari.Add(rezervare);
                }

                servTerminal.changeStateLoc(locuri);
                servTerminal.addSpectator(spectator);
                servTerminal.addRezervare(rezervari);

                reloadTable();

            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void TerminalApp_Load(object sender, EventArgs e)
        {

        }

        private void clearAllText()
        {
            numeText.Text = "";
            telefonText.Text = "";
            emailText.Text = "";
        }
    }
}
