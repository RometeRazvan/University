using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Faza2.Domain
{
    [Table("Loc")]
    public class Loc : DbContext
    {
        [Key()]
        public Guid id { get; set; }
        [StringLength(20)]
        public string pozitie { get; set; }
        public int pret { get; set; }
        public bool liber { get; set; }

        /*public Loc(string poz, int pre, bool lib)
        {
            this.id = Guid.NewGuid();
            this.pozitie = poz;
            this.liber = lib;
        }*/
    }
}
