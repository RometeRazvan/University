using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabCSharp_V3.Domain;
using System.Data.SQLite;

namespace LabCSharp_V3.Service
{
    interface IServUser
    {

        User findByName(string name);

    }
}
