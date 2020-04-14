﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;

namespace LabCSharp_V3.Tools
{
    class DBAdd
    {

        public string GetConnectionStringByName(string name)
        {
            string returnValue = null;

            ConnectionStringSettings settings = ConfigurationManager.ConnectionStrings[name];

            if(settings != null)
            {
                returnValue = settings.ConnectionString;
            }

            return returnValue;
        }

    }
}
