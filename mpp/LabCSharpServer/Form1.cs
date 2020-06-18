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
    public partial class Form1 : Form
    {

        private static NLog.Logger logger = NLog.LogManager.GetCurrentClassLogger();

        private ServiceUser servUser;

        private string nameDB;

        public Form1(string name)
        {
            InitializeComponent();

            nameDB = name;

            servUser = new ServiceUser(name);

            textPassword.PasswordChar = '*';

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
        private void clearText()
        {
            textUsername.Clear();
            textPassword.Clear();
        }

        private void clearLogInLabel()
        {
            labelLogIn.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string username = textUsername.Text;
                string password = textPassword.Text;

                User user = servUser.findByName(username);

                User userLogIn = new User(username, password);

                 if (user != null && user.EqualData(userLogIn))
                 {
                     Form2 form2 = new Form2();

                      form2.setData(nameDB);

                     form2.Activate();

                     this.Hide();

                     form2.ShowDialog();

                     this.Close();
                 }
                 else
                 {
                     labelLogIn.Text = "Date invalide";
                     clearText();
                 }
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            clearLogInLabel();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textPassword_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void textPassword_TextChanged(object sender, EventArgs e)
        {
            clearLogInLabel();
        }

    }
}
