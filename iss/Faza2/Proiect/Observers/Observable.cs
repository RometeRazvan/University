using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Faza2.Observers
{
    public interface Observable
    {
        void notifyObserver();
        void getNotified();
        void close();
    }
}
