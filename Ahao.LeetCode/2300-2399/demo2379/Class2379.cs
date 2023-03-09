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
            int l = 0, r = 0, cnt = 0;
            while (r < k)
            {
                cnt += blocks[r] == 'W' ? 1 : 0;
                r++;
            }
            int res = cnt;
            while (r < blocks.Length)
            {
                cnt += blocks[r] == 'W' ? 1 : 0;
                cnt -= blocks[l] == 'W' ? 1 : 0;
                res = Math.Min(res, cnt);
                l++;
                r++;
            }
            return res;
        }

        public int MinimumRecolors2(string blocks, int k)
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
