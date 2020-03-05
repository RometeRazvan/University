using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        SqlDataAdapter da = new SqlDataAdapter();
        DataSet ds = new DataSet();
        String str = "server=RAZVAN-LAPTOP;database=filme ; Integrated security=True";
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                String query = "select * from Angajat";
                SqlConnection con = new SqlConnection(str);
                SqlCommand cmd = new SqlCommand(query, con);
                da.SelectCommand = cmd;
                con.Open();
                da.Fill(ds, "filme");
                MessageBox.Show("connect with sql server");
                dataGridView1.DataSource = ds.Tables["filme"];
                con.Close();

            }
            catch (Exception es)

            {
                MessageBox.Show(es.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                using (SqlConnection conn2 = new SqlConnection(str))
                {
                    da.SelectCommand.Connection = conn2;
                    ds.Tables["filme"].Clear();
                    da.Fill(ds, "filme");
                }
            }
            catch (Exception ex)
            {

            }
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                String query = "select * from Concediu";
                SqlConnection con = new SqlConnection(str);
                SqlCommand cmd = new SqlCommand(query, con);
                da.SelectCommand = cmd;
                con.Open();
                da.Fill(ds, "filme");
                MessageBox.Show("connect with sql server");
                dataGridView1.DataSource = ds.Tables["filme"];
                con.Close();

            }
            catch (Exception es)

            {
                MessageBox.Show(es.Message);
            }
        }
    }
}