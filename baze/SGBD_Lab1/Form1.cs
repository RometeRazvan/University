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

namespace SGBD_Lab1
{
    public partial class Form1 : Form
    {
        SqlDataAdapter da= new SqlDataAdapter();
        DataSet ds = new DataSet();

        bool dataGrid2Written = false;

        string strConn = "server=RAZVAN-LAPTOP;database=filme ; Integrated security=True";


        public Form1()
        {
            InitializeComponent();
        }


        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                string query = "Select * from Concediu Where idAngajat=" + dataGridView1.CurrentRow.Cells[0].Value.ToString();
                SqlConnection conn = new SqlConnection(strConn);
                SqlCommand comm = new SqlCommand(query, conn);
                da.SelectCommand = comm;

                conn.Open();

                if (dataGrid2Written) ds.Tables["Concediu"].Clear();

                da.Fill(ds, "Concediu");
                dataGridView2.DataSource = ds.Tables["Concediu"];

                dataGrid2Written = true;

                textBox2.ReadOnly = true;

                textBox2.Text = this.dataGridView2.CurrentRow.Cells[1].Value.ToString();

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
                string query = "Select * from Angajat";
                SqlConnection conn = new SqlConnection(strConn);
                SqlCommand comm = new SqlCommand(query, conn);
                da.SelectCommand = comm;

                conn.Open();

                da.Fill(ds, "Angajat");
                //MessageBox.Show("Connect with sql server");
                dataGridView1.DataSource = ds.Tables["Angajat"];

                conn.Close();
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        { 
            Form2 f2 = new Form2();

            f2.textBox1.ReadOnly = true;
            f2.textBox2.ReadOnly = true;

            f2.textBox1.Text = this.dataGridView2.CurrentRow.Cells[0].Value.ToString();
            f2.textBox2.Text = this.dataGridView2.CurrentRow.Cells[1].Value.ToString();
            f2.textBox3.Text = this.dataGridView2.CurrentRow.Cells[2].Value.ToString();
            f2.textBox4.Text = this.dataGridView2.CurrentRow.Cells[3].Value.ToString();

            f2.setF1(this);

            f2.ShowDialog();

            
        }

        public void reloadDatagridview2()
        {
            try
            {
                string query = "Select * from Concediu Where idAngajat=" + dataGridView1.CurrentRow.Cells[0].Value.ToString();
                SqlConnection conn = new SqlConnection(strConn);
                SqlCommand comm = new SqlCommand(query, conn);
                da.SelectCommand = comm;

                conn.Open();

                if (dataGrid2Written) ds.Tables["Concediu"].Clear();

                da.Fill(ds, "Concediu");
                dataGridView2.DataSource = ds.Tables["Concediu"];

                dataGrid2Written = true;

                conn.Close();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string query = "Insert into Concediu Values(@1,@2, @3, @4)";
                SqlConnection conn = new SqlConnection(strConn);
                SqlCommand comm = new SqlCommand(query, conn);

                conn.Open();

                comm.Parameters.AddWithValue("@1", textBox1.Text);
                comm.Parameters.AddWithValue("@2", textBox2.Text);
                comm.Parameters.AddWithValue("@3", textBox3.Text);
                comm.Parameters.AddWithValue("@4", textBox4.Text);

                comm.ExecuteNonQuery();

                clearText();

                reloadDatagridview2();

                conn.Close();
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void clearText()
        {
            try
            {
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
                textBox4.Clear();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
