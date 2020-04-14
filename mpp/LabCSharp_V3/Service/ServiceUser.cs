using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabCSharp_V3.Repository;
using LabCSharp_V3.Domain;
using System.Data.SQLite;

namespace LabCSharp_V3.Service
{
    class ServiceUser : IServUser
    {

        RepoUser repo;

        public ServiceUser(string name)
        {
            repo = new RepoUser(name);
        }

        public User findByName(string name)
        {
            return repo.findByName(name);
        }
    }
}
