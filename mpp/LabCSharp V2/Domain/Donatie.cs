using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabCSharp_V2.Domain
{
    class Donatie
    {
        public string Nume { get; }
        public string Caz { get; }
        public string Adresa { get; }
        public string NrTel { get; }
        public int Suma { get; }
        public int Id { get; }

        public Donatie(string nume, string caz, string adresa, string nrTel, int suma, int id)
        {
            Nume = nume;
            Caz = caz;
            Adresa = adresa;
            NrTel = nrTel;
            Suma = suma;
            Id = id;
        }

        public Donatie(string nume, string caz, string adresa, string nrTel, int suma)
        {
            Nume = nume;
            Caz = caz;
            Adresa = adresa;
            NrTel = nrTel;
            Suma = suma;
        }

        public override string ToString()
        {
            return $"{nameof(Nume)} : {Nume}, {nameof(Caz)} : {Caz}" +
                   $"{nameof(Adresa)} : {Adresa}, {nameof(NrTel)} : {NrTel}" +
                   $"{nameof(Suma)} : {Suma}";
        }

        public bool EqualData(object obj)
        {
            if (GetType() != obj.GetType()) return false;
            return EqualString((Donatie)obj);
        }

        public bool EqualString(Donatie donatie)
        {
            return Nume.Equals(donatie.Nume) && Caz.Equals(donatie.Caz) && Adresa.Equals(donatie.Adresa) &&
                   NrTel.Equals(donatie.NrTel) && Suma == donatie.Suma;
        }
    }
}
