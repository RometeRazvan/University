using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SQLite;
using System.Configuration;
using LabCSharp_V3.Domain;
using LabCSharp_V3.Tools;
using LabCSharp_V3.Repository;
using LabCSharp_V3.Service;

namespace LabCSharp_V3
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            string name = "tasksDB";

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1(name));

            /*ServiceUser su = new ServiceUser(name); su.findByName("Razvan");
            ServiceDonatie sd = new ServiceDonatie(name); sd.findByName("Raz");
            ServCaritate sc = new ServCaritate(name); sc.findAll();*/
        }
    }

}
