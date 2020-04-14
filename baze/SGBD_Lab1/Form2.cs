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
    public partial class Form2 : Form
    {
        private Form1 f1;

        private SqlDataAdapter da = new SqlDataAdapter();

        string strConn = "server=RAZVAN-LAPTOP;database=filme ; Integrated security=True";


        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        public void setF1(Form1 f1)
        {
            this.f1 = f1;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string query = "Delete from Concediu where idConcediu = " + textBox1.Text;

                SqlConnection conn = new SqlConnection(strConn);

                SqlCommand comm = new SqlCommand(query, conn);

                conn.Open();

                comm.ExecuteNonQuery();

                conn.Close();

                f1.reloadDatagridview2();

                this.Close();

            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {

            try
            {
                string query = "Update Concediu set destinatie = @1, pret = @2 where idConcediu = @3";

                SqlConnection conn = new SqlConnection(strConn);

                SqlCommand comm = new SqlCommand(query, conn);

                conn.Open();

                comm.Parameters.AddWithValue("@1", textBox3.Text);
                comm.Parameters.AddWithValue("@2", textBox4.Text);
                comm.Parameters.AddWithValue("@3", textBox1.Text);

                comm.ExecuteNonQuery();

                conn.Close();

                f1.reloadDatagridview2();

                this.Close();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
