using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1732
{
    public class Class1732
    {
        public int LargestAltitude(int[] gain)
        {
            int ans = 0, sum = 0;
            foreach (int x in gain)
            {
                sum += x;
                ans = Math.Max(ans, sum);
            }
            return ans;
        }

    }
}
