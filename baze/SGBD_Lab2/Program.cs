using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SGBD_Lab1
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            string titlu = System.Configuration.ConfigurationManager.AppSettings["Titlu"];
            Form1 form = new Form1();
            form.Text = titlu;
            Application.Run(form);
        }
    }
}
