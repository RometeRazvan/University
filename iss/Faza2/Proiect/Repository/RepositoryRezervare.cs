using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Faza2.Domain;
using Faza2.Tools;
using Microsoft.Win32.SafeHandles;

namespace Faza2.Repository
{
    class RepositoryRezervare
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public RepositoryRezervare() { }

        public void add(List<Rezervare> list)
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    foreach (Rezervare rezervare in list)
                    {
                        contextTeatru.Rezervare.Add(rezervare);
                    }

                    contextTeatru.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public List<Rezervare> findByIdSpectator(Guid id)
        {
            try
            {
                List<Rezervare> list = new List<Rezervare>();

                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    foreach(Rezervare rezervare in contextTeatru.Rezervare.ToList())
                    {
                        if (rezervare.spectatorId == id)
                        {
                            list.Add(rezervare);
                        }
                    }
                }

                return list;
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public void deleteBySpectator(Spectator spectator)
        {
            try
            {
                using(ContextTeatru contextTeatru = new ContextTeatru())
                {
                    List<Rezervare> list = new List<Rezervare>();

                    foreach(Rezervare rezervare in contextTeatru.Rezervare.ToList())
                    {
                        if (rezervare.spectatorId == spectator.id)
                            list.Add(rezervare);
                    }

                    foreach(Rezervare rezervare in list)
                    {
                        contextTeatru.Rezervare.Remove(rezervare);
                    }

                    contextTeatru.SaveChanges();
                }
            }
            catch(Exception ex)
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
                    foreach (Rezervare rezervare in contextTeatru.Rezervare)
                        contextTeatru.Rezervare.Remove(rezervare);

                    contextTeatru.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }
    }
}
