using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1027
{
    public class Class1027
    {
        public int LongestArithSeqLength(int[] nums)
        {
            int minv = nums.Min();
            int maxv = nums.Max();
            int diff = maxv - minv;
            int ans = 1;
            for (int d = -diff; d <= diff; ++d)
            {
                int[] f = new int[maxv + 1];
                Array.Fill(f, -1);
                foreach (int num in nums)
                {
                    int prev = num - d;
                    if (prev >= minv && prev <= maxv && f[prev] != -1)
                    {
                        f[num] = Math.Max(f[num], f[prev] + 1);
                        ans = Math.Max(ans, f[num]);
                    }
                    f[num] = Math.Max(f[num], 1);
                }
            }
            return ans;
        }


    }
}
