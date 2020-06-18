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
    [Table("Rezervare")]
    public class Rezervare : DbContext
    {
        [Key()]
        public Guid id { get; set; }
        public Guid piesaId { get; set; }
        public Guid spectatorId { get; set; }
        public Guid locId { get; set; }
       /* [ForeignKey("piesaId")]
        public Piesa piesa { get; set; }
        [ForeignKey("spectatorId")]
        public Spectator spectator { get; set; }
        [ForeignKey("locId")]
        public Loc loc { get; set; }

        /*public Rezervare(Guid pid, Piesa pi, Guid sid, Spectator spec, Guid lid, Loc lc)
        {
            this.id = Guid.NewGuid();
            this.piesa = pi;
            this.spectator = spec;
            this.loc = lc;
            this.piesaId = pid;
            this.spectatorId = sid;
            this.locId = lid;
        }*/
    }
}
