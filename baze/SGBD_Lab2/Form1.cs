using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace SGBD_Lab1
{
    public partial class Form1 : Form
    {
        SqlDataAdapter da= new SqlDataAdapter();
        DataSet ds = new DataSet();

        bool dataGrid2Written = false;

        string strConn;
        string tabel1;
        string tabel2;
        string idTable1;


        public Form1()
        {
            InitializeComponent();

            try
            {
                strConn = System.Configuration.ConfigurationManager.AppSettings["StringConnection"];
                tabel1 = System.Configuration.ConfigurationManager.AppSettings["Parinte"];
                tabel2 = System.Configuration.ConfigurationManager.AppSettings["Copil"];
                idTable1 = System.Configuration.ConfigurationManager.AppSettings["Coloana"];
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }


        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                string query = "Select * from " + tabel2 + " Where " + idTable1 + " = " + dataGridView1.CurrentRow.Cells[0].Value.ToString();
                SqlConnection conn = new SqlConnection(strConn);
                SqlCommand comm = new SqlCommand(query, conn);
                da.SelectCommand = comm;

                conn.Open();

                if (dataGrid2Written) ds.Tables[tabel2].Clear();

                da.Fill(ds, tabel2);
                dataGridView2.DataSource = ds.Tables[tabel2];

                dataGrid2Written = true;
                conn.Close();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }


        private void Form1_Load_1(object sender, EventArgs e)
        {
            try
            {
                string query = "Select * from " + tabel1;
                SqlConnection conn = new SqlConnection(strConn);
                SqlCommand comm = new SqlCommand(query, conn);
                da.SelectCommand = comm;

                conn.Open();

                da.Fill(ds, tabel1);

                dataGridView1.DataSource = ds.Tables[tabel1];

                conn.Close();
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                SqlCommandBuilder builder = new SqlCommandBuilder(da);
                da.Update(ds, tabel2);
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void button2_MouseClick(object sender, MouseEventArgs e)
        {
            try
            {
                SqlCommandBuilder builder = new SqlCommandBuilder(da);
                da.Update(ds, tabel2);
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void button3_MouseClick(object sender, MouseEventArgs e)
        {
            try
            {
                if (dataGridView2.SelectedRows.Count > 0)
                {
                    int rows = dataGridView2.SelectedRows[0].Index;
                    dataGridView2.Rows.RemoveAt(rows);
                    SqlCommandBuilder builder = new SqlCommandBuilder(da);
                    da.Update(ds, tabel2);
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }
    }
}
