using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;

namespace LabCSharp_V2.Database
{
    class DBTool
    {
        public DBTool() {}

        public SQLiteConnection getMyConnection()
        {
            String connectionString = "URI = file:/Database/Database.db,Version = 3";
            var conn = new SQLiteConnection(connectionString);
            return conn;
        }

    }
}
