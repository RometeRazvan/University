using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using LabCSharp_V3.Domain;
using LabCSharp_V3.Service;

namespace LabCSharp_V3
{
    public partial class Form2 : Form
    {

        private static NLog.Logger logger = NLog.LogManager.GetCurrentClassLogger();

        private ServCaritate servCaritate;
        private ServiceDonatie serviceDonatie;

        public void setData(string name)
        {
            this.servCaritate = new ServCaritate(name);
            this.serviceDonatie = new ServiceDonatie(name);
        }

        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            reloadTable();
        }

        private void reloadTable()
        {
            try
            {
                DataTable tabel = new DataTable();

                tabel.Columns.Add("Id", typeof(int));
                tabel.Columns.Add("Nume", typeof(string));
                tabel.Columns.Add("Suma", typeof(int));

                foreach (Caritate caritate in servCaritate.findAll())
                {
                    tabel.Rows.Add(caritate.Id, caritate.Nume, caritate.Suma);
                }

                tabelCazuri.DataSource = tabel;
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void reloadTableDonatii(string name)
        {
            try
            {
                DataTable table = new DataTable();

                table.Columns.Add("Id", typeof(int));
                table.Columns.Add("Nume", typeof(string));
                table.Columns.Add("Caz", typeof(string));
                table.Columns.Add("Adresa", typeof(string));
                table.Columns.Add("Telefon", typeof(string));
                table.Columns.Add("Suma", typeof(string));

                foreach (Donatie donatie in serviceDonatie.findByName(name))
                {
                    table.Rows.Add(donatie.Id, donatie.Nume, donatie.Caz, donatie.Adresa, donatie.NrTel, donatie.Suma);
                }

                tabelDonatii.DataSource = table;
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            clearText();
        }

        private void clearText()
        {
            textNume.Clear();
            textAdresa.Clear();
            textNumar.Clear();
            textSuma.Clear();
        }

        private void buttonAdauga_Click(object sender, EventArgs e)
        {
            try
            {

                string nume = textNume.Text;
                string adresa = textAdresa.Text;
                string numar = textNumar.Text;
                int suma = Convert.ToInt32(textSuma.Text);

                string caz = tabelCazuri.CurrentRow.Cells[1].Value.ToString();

                //MessageBox.Show(nume + "\n" + adresa + "\n" + numar + "\n" + suma + "\n" + caz);

                Donatie donatie = serviceDonatie.save(nume, caz, adresa, numar, suma);

                servCaritate.updateSuma(caz, suma);

                reloadTable();

                clearText();
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void buttonLogOut_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            string text = textCauta.Text;

            reloadTableDonatii(text);
        }

        private void tabelDonatii_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            textNume.Text = tabelDonatii.CurrentRow.Cells[1].Value.ToString();
            textAdresa.Text = tabelDonatii.CurrentRow.Cells[3].Value.ToString();
            textNumar.Text = tabelDonatii.CurrentRow.Cells[4].Value.ToString();
        }
    }
}
