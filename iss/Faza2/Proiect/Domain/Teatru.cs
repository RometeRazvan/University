using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Data.Entity;

namespace Faza2.Domain
{
    [Table("Teatru")]
    public class Teatru : DbContext
    {
        [Key(), DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public Guid id { get; set; }
        [StringLength(20)]
        public string nume { get; set; }
    }
}
