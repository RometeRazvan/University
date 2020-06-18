using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;
using LabCSharp_V3.Domain;
using LabCSharp_V3.Tools;

namespace LabCSharp_V3.Repository
{
    class RepoUser : IRepoUser
    {

        private static NLog.Logger logger = NLog.LogManager.GetCurrentClassLogger();

        string nameDB;

        public RepoUser(string name)
        {
            nameDB = name;
        }

        public User findByName(string name)
        {
            try
            {

                User user = null;

                string query = "Select * from Users where nume = @1";

                using (SQLiteConnection conn = new SQLiteConnection(new DBAdd().GetConnectionStringByName(nameDB)))
                {
                    using(SQLiteCommand myCommand = new SQLiteCommand(query, conn))
                    {
                        conn.Open();

                        myCommand.Parameters.AddWithValue("@1", name);

                        SQLiteDataReader dr = myCommand.ExecuteReader();

                        if (dr.Read())
                        {
                            user = new User(dr.GetString(1), dr.GetString(2), dr.GetInt32(0));
                        }

                        dr.Close();
                    }
                }

                return user;
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }
    }
}
