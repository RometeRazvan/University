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
using Faza2.Service;

namespace Faza2.Windows
{
    public partial class ManagerLogIn : Form
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        private ServiceManager servManager;
        public ManagerLogIn()
        {
            InitializeComponent();
            loadData();
        }

        private void loadData()
        {
            try
            {
                servManager = new ServiceManager();

                passwordText.PasswordChar = '*';
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        private void ManagerLogIn_Load(object sender, EventArgs e)
        {

        }

        private void logInButton_Click(object sender, EventArgs e)
        {
            try
            {
                string username = usernameText.Text;
                string password = passwordText.Text;

                bool val = servManager.validateManager(username, password);

                if(val)
                {
                    ManagerApp managerApp = new ManagerApp();

                    this.Hide();

                    managerApp.ShowDialog();

                    this.Close();
                }
                else
                {
                    errorLabel.Text = "Date invalide !!!";
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);

                errorLabel.Text = "Date invalide !!!";
            }
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
