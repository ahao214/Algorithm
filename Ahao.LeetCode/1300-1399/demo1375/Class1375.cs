using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1375
{
    public class Class1375
    {

        public int NumTimesAllBlue(int[] flips)
        {
            int n = flips.Length;
            int ans = 0, right = 0;
            for (int i = 0; i < n; ++i)
            {
                right = Math.Max(right, flips[i]);
                if (right == i + 1)
                {
                    ++ans;
                }
            }
            return ans;
        }


    }
}
