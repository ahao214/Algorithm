using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2379
{
    public class Class2379
    {
        public int MinimumRecolors(string blocks, int k)
        {
            int res = int.MaxValue;
            int left = 0, right = k;
            while (right <= blocks.Length)
            {
                string s = blocks.Substring(left, k);
                int tmpCount = CountWhite(s);
                res = Math.Min(res, tmpCount);
                left++;
                right++;
            }

            return res;
        }

        public int CountWhite(string s)
        {
            int count = 0;
            for (int i = 0; i < s.Length; i++)
                count += s[i] == 'W' ? 1 : 0;
            return count;
        }
    }
}
