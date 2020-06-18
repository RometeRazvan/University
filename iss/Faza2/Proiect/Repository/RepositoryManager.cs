using System;
using System.Collections.Generic;
using System.Drawing.Text;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Faza2.Domain;
using Faza2.Tools;

namespace Faza2.Repository
{
    public class RepositoryManager
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public RepositoryManager() {}

        public bool validateManager(string username, string password)
        {
            try
            {
                using(ContextTeatru contextTeatru = new ContextTeatru())
                {
                    bool val = false;

                    foreach(Manager manager in contextTeatru.Manager.ToList())
                    {
                        if (manager.username == username && manager.password == password)
                        {
                            val = true;
                            break;
                        }
                    }

                    return val;
                }
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }

            return false;
        }
    }
}
