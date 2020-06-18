using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Faza2.Domain;
using Faza2.Tools;

namespace Faza2.Repository
{
    class RepositorySpectator
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public RepositorySpectator() { }

        public void add(Spectator spectator)
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    contextTeatru.Spectator.Add(spectator);

                    contextTeatru.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public Spectator findByData(string nume, string telefon, string email)
        {
            try
            {
                using(ContextTeatru contextTeatru = new ContextTeatru())
                {
                    Spectator spectator = contextTeatru.Spectator.FirstOrDefault(item => item.nume == nume && item.telefon == telefon && item.email == email);

                    return spectator;
                }
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public void deleteByData(string nume, string telefon, string email)
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    Spectator spectator = contextTeatru.Spectator.FirstOrDefault(item => item.nume == nume && item.telefon == telefon && item.email == email);

                    contextTeatru.Spectator.Remove(spectator);

                    contextTeatru.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public void deleteAll()
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    foreach (Spectator spectator in contextTeatru.Spectator)
                        contextTeatru.Spectator.Remove(spectator);

                    contextTeatru.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public List<Spectator> findAll()
        {
            try
            {
                List<Spectator> list = new List<Spectator>();

                using(ContextTeatru contextTeatru = new ContextTeatru())
                {
                    foreach(Spectator spectator in contextTeatru.Spectator.ToList())
                    {
                        list.Add(spectator);
                    }
                }

                return list;
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }
    }
}
