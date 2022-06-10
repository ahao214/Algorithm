using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo730
{
    public class Class730
    {
        /// <summary>
        /// //动态规划(使用三维数组)
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public int CountPalindromicSubsequences(string s)
        {
            const int MOD = 1000000007;
            int n = s.Length;
            int[,,] dp = new int[4, n, n];
            for (int i = 0; i < n; i++)
            {
                dp[s[i] - 'a', i, i] = 1;
            }

            for (int len = 2; len <= n; len++)
            {
                for (int i = 0; i + len <= n; i++)
                {
                    int j = i + len - 1;
                    for (char c = 'a'; c <= 'd'; c++)
                    {
                        int k = c - 'a';
                        if (s[i] == c && s[j] == c)
                        {
                            dp[k, i, j] = (2 + (dp[0, i + 1, j - 1] + dp[1, i + 1, j - 1]) % MOD + (dp[2, i + 1, j - 1] + dp[3, i + 1, j - 1]) % MOD) % MOD;
                        }
                        else if (s[i] == c)
                        {
                            dp[k, i, j] = dp[k, i, j - 1];
                        }
                        else if (s[j] == c)
                        {
                            dp[k, i, j] = dp[k, i + 1, j];
                        }
                        else
                        {
                            dp[k, i, j] = dp[k, i + 1, j - 1];
                        }
                    }
                }
            }

            int res = 0;
            for (int i = 0; i < 4; i++)
            {
                res = (res + dp[i, 0, n - 1]) % MOD;
            }
            return res;
        }



        /// <summary>
        /// 动态规划(使用二维数组)
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public int CountPalindromicSubsequences2(string s)
        {
            const int MOD = 1000000007;
            int n = s.Length;
            int[,] dp = new int[n, n];
            int[,] next = new int[n, 4];
            int[,] pre = new int[n, 4];

            for (int i = 0; i < n; i++)
            {
                dp[i, i] = 1;
            }

            int[] pos = new int[4];
            Array.Fill(pos, -1);

            for (int i = 0; i < n; i++)
            {
                for (int c = 0; c < 4; c++)
                {
                    pre[i, c] = pos[c];
                }
                pos[s[i] - 'a'] = i;
            }

            pos[0] = pos[1] = pos[2] = pos[3] = n;

            for (int i = n - 1; i >= 0; i--)
            {
                for (int c = 0; c < 4; c++)
                {
                    next[i, c] = pos[c];
                }
                pos[s[i] - 'a'] = i;
            }

            for (int len = 2; len <= n; len++)
            {
                for (int i = 0; i + len <= n; i++)
                {
                    int j = i + len - 1;
                    if (s[i] == s[j])
                    {
                        int low = next[i, s[i] - 'a'];
                        int high = pre[j, s[i] - 'a'];
                        if (low > high)
                        {
                            dp[i, j] = (2 + dp[i + 1, j - 1] * 2) % MOD;
                        }
                        else if (low == high)
                        {
                            dp[i, j] = (1 + dp[i + 1, j - 1] * 2) % MOD;
                        }
                        else
                        {
                            dp[i, j] = (dp[i + 1, j - 1] * 2 % MOD - dp[low + 1, high - 1] + MOD) % MOD;
                        }
                    }
                    else
                    {
                        dp[i, j] = ((dp[i + 1, j] + dp[i, j - 1]) % MOD - dp[i + 1, j - 1] + MOD) % MOD;
                    }
                }
            }

            return dp[0, n - 1];
        }

    }
}
