using System;
using System.Collections.Generic;
using System.Data.Entity.Migrations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Faza2.Domain;
using Faza2.Tools;

namespace Faza2.Repository
{
    class RepositoryLoc
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public RepositoryLoc() { }

        public List<Loc> findAll()
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    List<Loc> list = new List<Loc>();

                    foreach(Loc loc in contextTeatru.Loc.ToList())
                    {
                        list.Add(loc);
                    }

                    return list;
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public void changeState(List<string> list)
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    foreach(string str in list)
                    {
                        Loc loc = contextTeatru.Loc.FirstOrDefault(item => item.pozitie == str);

                        if (loc.liber == true)
                            loc.liber = false;
                        else loc.liber = true;

                        contextTeatru.Loc.AddOrUpdate(loc);

                        contextTeatru.SaveChanges();
                    }
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public Loc findByPozitie(string pozitie)
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    Loc loc = contextTeatru.Loc.FirstOrDefault(item => item.pozitie == pozitie);

                    return loc;
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public Loc findById(Guid id)
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    Loc loc = contextTeatru.Loc.FirstOrDefault(item => item.id == id);

                    return loc;
                }
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }
    }
}
