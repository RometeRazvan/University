using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;
using LabCSharp_V3.Tools;
using LabCSharp_V3.Domain;

namespace LabCSharp_V3.Repository
{
    class RepoCaritate : IRepoCaritate
    {
        private static NLog.Logger logger = NLog.LogManager.GetCurrentClassLogger();

        string nameDB;

        public RepoCaritate(string name)
        {
            nameDB = name;
        }

        public List<Caritate> findAll()
        {
            try
            {
                using (SQLiteConnection conn = new SQLiteConnection(new DBAdd().GetConnectionStringByName(nameDB)))
                {
                    List<Caritate> listCaritate = new List<Caritate>();

                    string query = "Select * from CazuriCaritabile";

                    using (SQLiteCommand myCommand = new SQLiteCommand(query, conn))
                    {
                        conn.Open();

                        SQLiteDataReader dr = myCommand.ExecuteReader();

                        while (dr.Read())
                        {
                            Caritate caritate = new Caritate(dr.GetString(1), dr.GetInt32(2), dr.GetInt32(0));

                            listCaritate.Add(caritate);
                        }

                        dr.Close();

                        return listCaritate;
                    }
                }

            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public void updateSuma(string caz, int suma)
        {
            try
            {
                using (SQLiteConnection conn = new SQLiteConnection(new DBAdd().GetConnectionStringByName(nameDB)))
                {
                    string query = "Update CazuriCaritabile set suma = suma + @1 where nume = @2";

                    using (SQLiteCommand myCommand = new SQLiteCommand(query, conn))
                    {
                        conn.Open();

                        myCommand.Parameters.AddWithValue("@1", suma);
                        myCommand.Parameters.AddWithValue("@2", caz);

                        myCommand.ExecuteNonQuery();
                    }
                }
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }
    }
}
