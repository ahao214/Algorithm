using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1335
{
    public class Class1335
    {

        public int MinDifficulty(int[] jobDifficulty, int d)
        {
            int n = jobDifficulty.Length;
            if (n < d)
            {
                return -1;
            }
            int[][] dp = new int[d + 1][];
            for (int i = 0; i <= d; ++i)
            {
                dp[i] = new int[n];
                Array.Fill(dp[i], 0x3f3f3f3f);
            }
            int ma = 0;
            for (int i = 0; i < n; ++i)
            {
                ma = Math.Max(ma, jobDifficulty[i]);
                dp[0][i] = ma;
            }
            for (int i = 1; i < d; ++i)
            {
                for (int j = i; j < n; ++j)
                {
                    ma = 0;
                    for (int k = j; k >= i; --k)
                    {
                        ma = Math.Max(ma, jobDifficulty[k]);
                        dp[i][j] = Math.Min(dp[i][j], ma + dp[i - 1][k - 1]);
                    }
                }
            }
            return dp[d - 1][n - 1];
        }


        public int MinDifficulty2(int[] jobDifficulty, int d)
        {
            int n = jobDifficulty.Length;
            if (n < d)
            {
                return -1;
            }
            int[] dp = new int[n];
            for (int i = 0, j = 0; i < n; ++i)
            {
                j = Math.Max(j, jobDifficulty[i]);
                dp[i] = j;
            }
            for (int i = 1; i < d; ++i)
            {
                int[] ndp = new int[n];
                Array.Fill(ndp, 0x3f3f3f3f);
                for (int j = i; j < n; ++j)
                {
                    int ma = 0;
                    for (int k = j; k >= i; --k)
                    {
                        ma = Math.Max(ma, jobDifficulty[k]);
                        ndp[j] = Math.Min(ndp[j], ma + dp[k - 1]);
                    }
                }
                dp = ndp;
            }
            return dp[n - 1];
        }

    }
}
