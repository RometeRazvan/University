using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;

namespace Faza2.Tools
{
    class DBAdress
    {

        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public string getConnString(string name)
        {
            string connStr = null;

            try
            {
                connStr = ConfigurationManager.ConnectionStrings[name].ConnectionString;
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }

            return connStr;
        }
    }
}
