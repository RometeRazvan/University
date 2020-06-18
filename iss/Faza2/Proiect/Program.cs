using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;
using Faza2.Domain;
using Faza2.Tools;

using Faza2.Service;
using Faza2.Windows;
using System.Threading;

namespace Faza2
{
    static class Program
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
                        //When we have closed the last of the "starting" forms, 
                        //end the program.
                        if (Interlocked.Decrement(ref openForms) == 0)
                            ExitThread();
                    };

                    form.Show();
                }
            }
        }
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            ServiceTerminal servTerminal = new ServiceTerminal();

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MultiFormContext(new ManagerLogIn()));
        }
    }
}
