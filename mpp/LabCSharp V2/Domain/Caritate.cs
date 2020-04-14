using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabCSharp_V2.Domain
{
    class Caritate
    {
        public string Nume { get; }
        public int Suma { get; set; }
        public int Id { get; }

        public Caritate(string nume, int suma, int id)
        {
            Nume = nume;
            Suma = suma;
            Id = id;
        }

        public Caritate(string nume, int suma)
        {
            Nume = nume;
            Suma = suma;
        }

        public override string ToString()
        {
            return $"{nameof(Nume)} : {Nume}, {nameof(Suma)} : {Suma}";
        }

        public bool EqualData(object obj)
        {
            if (GetType() != obj.GetType()) return false;
            return EqualString((Caritate)obj);
        }

        public bool EqualString(Caritate caritate)
        {
            return Nume.Equals(caritate.Nume) && Suma == caritate.Suma;
        }
    }
}
