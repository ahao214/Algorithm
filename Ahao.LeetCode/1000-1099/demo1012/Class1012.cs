using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1012
{
    public class Class1012
    {
        int[][] dp;

        public int NumDupDigitsAtMostN(int n)
        {
            string sn = n.ToString();
            dp = new int[sn.Length][];
            for (int i = 0; i < sn.Length; i++)
            {
                dp[i] = new int[1 << 10];
                Array.Fill(dp[i], -1);
            }
            return n + 1 - F(0, sn, 0, true);
        }

        public int F(int mask, string sn, int i, bool same)
        {
            if (i == sn.Length)
            {
                return 1;
            }
            if (!same && dp[i][mask] >= 0)
            {
                return dp[i][mask];
            }
            int res = 0, t = same ? (sn[i] - '0') : 9;
            for (int k = 0; k <= t; k++)
            {
                if ((mask & (1 << k)) != 0)
                {
                    continue;
                }
                res += F(mask == 0 && k == 0 ? mask : mask | (1 << k), sn, i + 1, same && k == t);
            }
            if (!same)
            {
                dp[i][mask] = res;
            }
            return res;
        }
    }
}
