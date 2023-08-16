using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1444
{
    public class Class1444
    {
        public int Ways(string[] pizza, int k)
        {
            int m = pizza.Length, n = pizza[0].Length, mod = 1_000_000_007;
            int[][] apples = new int[m + 1][];
            for (int i = 0; i <= m; i++)
            {
                apples[i] = new int[n + 1];
            }
            int[][][] dp = new int[k + 1][][];
            for (int i = 0; i <= k; i++)
            {
                dp[i] = new int[m + 1][];
                for (int j = 0; j <= m; j++)
                {
                    dp[i][j] = new int[n + 1];
                }
            }

            // 预处理
            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    apples[i][j] = apples[i][j + 1] + apples[i + 1][j] - apples[i + 1][j + 1] + (pizza[i][j] == 'A' ? 1 : 0);
                    dp[1][i][j] = apples[i][j] > 0 ? 1 : 0;
                }
            }

            for (int ki = 2; ki <= k; ki++)
            {
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        // 水平方向切
                        for (int i2 = i + 1; i2 < m; i2++)
                        {
                            if (apples[i][j] > apples[i2][j])
                            {
                                dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i2][j]) % mod;
                            }
                        }
                        // 垂直方向切
                        for (int j2 = j + 1; j2 < n; j2++)
                        {
                            if (apples[i][j] > apples[i][j2])
                            {
                                dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i][j2]) % mod;
                            }
                        }
                    }
                }
            }
            return dp[k][0][0];
        }




        public int Ways2(string[] pizza, int k)
        {
            int MOD = (int)1e9 + 7;
            int m = pizza.Length, n = pizza[0].Length;
            var sum = new int[m + 1][];
            var f = new int[m + 1][];
            for (int i = 0; i < m + 1; i++)
            {
                sum[i] = new int[n + 1];
                f[i] = new int[n + 1];
            }
            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    sum[i][j] = sum[i][j + 1] + sum[i + 1][j] - sum[i + 1][j + 1] + (pizza[i][j] & 1);
                    if (sum[i][j] > 0) f[i][j] = 1;
                }
            }

            while (--k > 0)
            {
                var colS = new int[n]; // colS[j] 表示 f 第 j 列的后缀和
                for (int i = m - 1; i >= 0; i--)
                {
                    int rowS = 0; // f[i] 的后缀和
                    for (int j = n - 1; j >= 0; j--)
                    {
                        int tmp = f[i][j];
                        if (sum[i][j] == sum[i][j + 1]) // 左边界没有苹果
                            f[i][j] = f[i][j + 1];
                        else if (sum[i][j] == sum[i + 1][j]) // 上边界没有苹果
                            f[i][j] = f[i + 1][j];
                        else // 左边界上边界都有苹果，那么无论怎么切都有苹果
                            f[i][j] = (rowS + colS[j]) % MOD;
                        rowS = (rowS + tmp) % MOD;
                        colS[j] = (colS[j] + tmp) % MOD;
                    }
                }
            }
            return f[0][0];
        }


    }
}
