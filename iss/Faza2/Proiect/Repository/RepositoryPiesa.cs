using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Faza2.Domain;
using Faza2.Tools;

namespace Faza2.Repository
{
    class RepositoryPiesa
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public RepositoryPiesa() { }

        public List<Piesa> findByTeatruId(Guid id)
        {
            try
            {
                List<Piesa> list = new List<Piesa>();

                using(ContextTeatru contextTeatru = new ContextTeatru())
                {
                    foreach(Piesa piesa in contextTeatru.Piesa.ToList())
                    {
                        if (piesa.teatruId == id)
                            list.Add(piesa);
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

        public Piesa findByNume(string nume)
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    foreach(Piesa piesa in contextTeatru.Piesa.ToList())
                    {
                        if (piesa.nume == nume)
                            return piesa;
                    }
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
