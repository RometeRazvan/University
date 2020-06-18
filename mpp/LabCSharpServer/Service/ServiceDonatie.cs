using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabCSharp_V3.Domain;
using LabCSharp_V3.Repository;
using System.Windows.Forms;

namespace LabCSharp_V3.Service
{
    class ServiceDonatie : IServiceDonatie
    {

        private static NLog.Logger logger = NLog.LogManager.GetCurrentClassLogger();

        RepoDonatie rd;

        public ServiceDonatie(string name)
        {
            rd = new RepoDonatie(name);
        }

        public Donatie save(string nume, string caz, string adresa, string nrTel, int suma)
        {
            try
            {
                Donatie donatie = new Donatie(nume, caz, adresa, nrTel, suma);

                rd.save(donatie);

                return donatie;
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public List<Donatie> findByName(string name)
        {
            return rd.findByName(name);
        }

    }
}
