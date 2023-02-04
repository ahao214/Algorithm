using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1798
{
    public class Class1798
    {
        public int GetMaximumConsecutive(int[] coins)
        {
            int res = 1;
            Array.Sort(coins);
            foreach (int i in coins)
            {
                if (i > res)
                {
                    break;
                }
                res += i;
            }
            return res;
        }
    }
}
