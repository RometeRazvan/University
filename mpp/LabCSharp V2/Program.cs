using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using Mono.Data.Sqlite;

namespace LabCSharp_V2
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
            // Application.Run(new Form1

            string source = "Data source = /Database/Database.db";
            string sqlCom = "Select * from Users where id = 1";
            using (var conn = new SqliteConnection(source))
            {
                conn.Open();
                Console.WriteLine("!!!!!!!!!");
                var cmd = new SqliteCommand(sqlCom, conn);
                cmd.ExecuteReader();
            }

        }
    }
}
