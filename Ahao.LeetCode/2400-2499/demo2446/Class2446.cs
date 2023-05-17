using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2446
{
    public class Class2446
    {

        public bool HaveConflict(string[] event1, string[] event2)
        {
            return !(event1[1].CompareTo(event2[0]) < 0 || event2[1].CompareTo(event1[0]) < 0);
        }


    }
}
