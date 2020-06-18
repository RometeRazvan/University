using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabCSharp_V3.Domain;
using LabCSharp_V3.Repository   ;


namespace LabCSharp_V3.Service
{
    class ServCaritate : IServCaritate
    {

        RepoCaritate rc;

        public ServCaritate(string name)
        {
            rc = new RepoCaritate(name);
        }

        public List<Caritate> findAll()
        { 
            return rc.findAll();
        }

        public void updateSuma(string caz, int suma)
        {
            rc.updateSuma(caz, suma);
        }

    }
}
