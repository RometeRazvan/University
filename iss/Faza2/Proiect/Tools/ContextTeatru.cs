using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;

using Faza2.Domain;

namespace Faza2.Tools
{
    class ContextTeatru : DbContext
    {

        public ContextTeatru() : base("name=db") { }
        public DbSet<Teatru> Teatru { get; set; }
        public DbSet<Piesa> Piesa { get; set; }
        public DbSet<Manager> Manager { get; set; }
        public DbSet<Loc> Loc { get; set; }
        public DbSet<Spectator> Spectator { get; set; }
        public DbSet<Rezervare> Rezervare { get; set; }
    }
}
