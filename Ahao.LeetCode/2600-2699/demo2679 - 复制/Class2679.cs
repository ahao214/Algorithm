using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2678
{
    public class Class2678
    {
        public int CountSeniors(string[] details)
        {
            int res = 0;
            foreach (var item in details)
            {
                int age = Convert.ToInt32(item.Substring(11, 2));
                if (age > 60)
                {
                    res += 1;
                }
            }
            return res;
        }


    }
}
