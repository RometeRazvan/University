using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabCSharp_V3.Domain;

namespace LabCSharp_V3.Repository
{
    interface IRepoCaritate
    {
        List<Caritate> findAll();

        void updateSuma(string caz, int suma);
    }
}
