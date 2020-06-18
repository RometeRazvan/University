using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabCSharp_V3.Domain;
using LabCSharp_V3.Tools;
using System.Data.SQLite;
using System.Windows.Forms;

namespace LabCSharp_V3.Repository
{
    class RepoDonatie : IRepoDonatie
    {
        private static NLog.Logger logger = NLog.LogManager.GetCurrentClassLogger();

        string nameDB;

        public RepoDonatie(string name)
        {
            nameDB = name;
        }

        public Donatie save(Donatie donatie)
        {

            try
            {

                using(SQLiteConnection conn = new SQLiteConnection(new DBAdd().GetConnectionStringByName(nameDB)))
                {
                    string query = "Insert into Donatii(nume, caz, adresa, nrTel, suma) Values(@1, @2, @3, @4, @5)";

                    using (SQLiteCommand myCommand = new SQLiteCommand(query, conn))
                    {
                        conn.Open();

                        myCommand.Parameters.AddWithValue("@1", donatie.Nume);
                        myCommand.Parameters.AddWithValue("@2", donatie.Caz);
                        myCommand.Parameters.AddWithValue("@3", donatie.Adresa);
                        myCommand.Parameters.AddWithValue("@4", donatie.NrTel);
                        myCommand.Parameters.AddWithValue("@5", donatie.Suma);

                        //MessageBox.Show(myCommand.ToString());

                        myCommand.ExecuteNonQuery();

                        conn.Close();
                    }
                }
                
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public List<Donatie> findByName(string name)
        {

            try
            {

                using (SQLiteConnection conn = new SQLiteConnection(new DBAdd().GetConnectionStringByName(nameDB)))
                {
                    List<Donatie> listDonatie = new List<Donatie>();

                    string query = "Select * from Donatii where charindex(@1, nume) > 0";

                    using (SQLiteCommand myCommand = new SQLiteCommand(query, conn))
                    {
                        conn.Open();

                        myCommand.Parameters.AddWithValue("@1", name);

                        SQLiteDataReader dr = myCommand.ExecuteReader();

                        while (dr.Read())
                        {

                            Donatie donatie = new Donatie(dr.GetString(1), dr.GetString(2), dr.GetString(3), dr.GetString(4), dr.GetInt32(5), dr.GetInt32(0));

                            listDonatie.Add(donatie);

                        }

                        dr.Close();

                        return listDonatie;
                    }
                }
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

    }
}
