using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Faza2.Domain;
using Faza2.Tools;

namespace Faza2.Repository
{
    class RepositoryTeatru
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public RepositoryTeatru() { }

        public Teatru findByNume(string nume)
        {
            try
            {
                using (ContextTeatru contextTeatru = new ContextTeatru())
                {
                    foreach(Teatru teatru in contextTeatru.Teatru.ToList())
                    {
                        if (teatru.nume == nume)
                            return teatru;
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
