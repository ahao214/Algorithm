using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2609
{
    public class Class2609
    {
        public int FindTheLongestBalancedSubstring(string s)
        {
            int res = 0;
            int n = s.Length;
            int[] count = new int[2];
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    count[1]++;
                    res = Math.Max(res, 2 * Math.Min(count[0], count[1]));
                }
                else if (i == 0 || s[i - 1] == '1')
                {
                    count[0] = 1;
                    count[1] = 0;
                }
                else
                {
                    count[0]++;
                }
            }
            return res;
        }

    }
}
