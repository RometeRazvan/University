using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabCSharp_V3.Domain;

namespace LabCSharp_V3.Service
{
    interface IServiceDonatie
    {

        Donatie save(string nume, string caz, string adresa, string nrTel, int suma);

        List<Donatie> findByName(string name);

    }
}
