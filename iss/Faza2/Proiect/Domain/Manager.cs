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
    [Table("Manager")]
    public class Manager : DbContext
    {
        [Key(), DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public Guid id { get; set; }
        [StringLength(20)]
        public string username { get; set; }
        [StringLength(20)]
        public string password { get; set; }
        public Guid teatruId { get; set; }
        [ForeignKey("teatruId")]
        public Teatru teatru { get; set; }
    }
}
