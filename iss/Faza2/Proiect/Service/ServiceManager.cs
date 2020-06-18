using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Faza2.Domain;
using Faza2.Repository;

namespace Faza2.Service
{
    public class ServiceManager
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        private RepositoryManager repoManager;
        private RepositoryTeatru repoTeatru;
        private RepositoryPiesa repoPiesa;

        public ServiceManager() {
            repoManager = new RepositoryManager();
            repoTeatru = new RepositoryTeatru();
            repoPiesa = new RepositoryPiesa();
        }

        public bool validateManager(string username, string password)
        {
            try
            {
                return repoManager.validateManager(username, password);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return false;
        }

        public Teatru findTeatruByNume(string nume)
        {
            try
            {
                return repoTeatru.findByNume(nume);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public List<Piesa> findPiesaByTeatruId(Guid id)
        {
            try
            {
                return repoPiesa.findByTeatruId(id);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public Piesa findPiesaByNume(string nume)
        {
            try
            {
                return repoPiesa.findByNume(nume);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }
    }
}
