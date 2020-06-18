using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Faza2.Domain
{
    [Table("Spectator")]
    public class Spectator
    {
        [Key()]
        public Guid id { get; set; }
        [StringLength(20)]
        public string nume { get; set; }
        [StringLength(20)]
        public string telefon { get; set; }
        [StringLength(30)]
        public string email { get; set; }
        
        /*public Spectator(string num, string tel, string e)
        {
            this.id = Guid.NewGuid();
            this.nume = num;
            this.telefon = tel;
            this.email = e;
        }*/
    }
}
