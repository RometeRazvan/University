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
    [Table("Piesa")]
    public class Piesa : DbContext
    {
        [Key(), DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public Guid id { get; set; }
        public Guid teatruId { get; set; }
        [StringLength(20)]
        public string nume { get; set; }
        [ForeignKey("teatruId")]
        public Teatru teatru { get; set; }
        /*public Piesa(string nume, Guid teatruId, Teatru teatru)
        {
            this.id = Guid.NewGuid();
            this.nume = nume;
            this.teatruId = teatruId;
            this.teatru = teatru;
        }*/
    }
}
