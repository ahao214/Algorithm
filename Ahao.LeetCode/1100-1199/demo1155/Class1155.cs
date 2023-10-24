using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1155
{
    public class Class1155
    {
        public int NumRollsToTarget(int n, int k, int target)
        {
            const int MODULO = 1000000007;
            long[][] dp = new long[n + 1][];
            for (int i = 0; i <= n; i++)
            {
                dp[i] = new long[target + 1];
            }
            dp[0][0] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= target; j++)
                {
                    int maxNum = Math.Min(k, j);
                    for (int d = 1; d <= maxNum; d++)
                    {
                        dp[i][j] += dp[i - 1][j - d];
                    }
                    dp[i][j] %= MODULO;
                }
            }
            return (int)dp[n][target];
        }

        const int MOD = 1000000007;

        public int NumRollsToTarget2(int n, int k, int target)
        {
            int[][] f = new int[n + 1][];
            for (int i = 0; i <= n; ++i)
            {
                f[i] = new int[target + 1];
            }
            f[0][0] = 1;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 0; j <= target; ++j)
                {
                    for (int x = 1; x <= k; ++x)
                    {
                        if (j - x >= 0)
                        {
                            f[i][j] = (f[i][j] + f[i - 1][j - x]) % MOD;
                        }
                    }
                }
            }
            return f[n][target];
        }


        public int NumRollsToTarget3(int n, int k, int target)
        {
            int[] f = new int[target + 1];
            f[0] = 1;
            for (int i = 1; i <= n; ++i)
            {
                int[] g = new int[target + 1];
                for (int j = 0; j <= target; ++j)
                {
                    for (int x = 1; x <= k; ++x)
                    {
                        if (j - x >= 0)
                        {
                            g[j] = (g[j] + f[j - x]) % MOD;
                        }
                    }
                }
                f = g;
            }
            return f[target];
        }


        public int NumRollsToTarget4(int n, int k, int target)
        {
            int[] f = new int[target + 1];
            f[0] = 1;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = target; j >= 0; --j)
                {
                    f[j] = 0;
                    for (int x = 1; x <= k; ++x)
                    {
                        if (j - x >= 0)
                        {
                            f[j] = (f[j] + f[j - x]) % MOD;
                        }
                    }
                }
            }
            return f[target];
        }

    }
}
