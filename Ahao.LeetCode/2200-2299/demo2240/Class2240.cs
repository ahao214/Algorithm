using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2200_2299.demo2240
{
    public class Class2240
    {
        public long WaysToBuyPensPencils(int total, int cost1, int cost2)
        {
            if (cost1 < cost2)
            {
                return WaysToBuyPensPencils(total, cost2, cost1);
            }
            long res = 0, cnt = 0;
            while (cnt * cost1 <= total)
            {
                res += (total - cnt * cost1) / cost2 + 1;
                cnt++;
            }
            return res;
        }


    }
}
