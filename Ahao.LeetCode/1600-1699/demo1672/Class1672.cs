using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1672
{
    public class Class1673
    {
        public int MaximumWealth(int[][] accounts)
        {
            int res = int.MinValue;
            foreach (int[] count in accounts)
            {
                res = Math.Max(res, count.Sum());
            }
            return res;
        }
    }
}
