using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 583. 两个字符串的删除操作
    /// </summary>
    public class MinDistance
    {
        public int Method(string word1, string word2)
        {
            //求出两个字符串的最长公共子序列，两个字符串的长度分别减去最长公共子序列的长度，即为所求结果
            int m = word1.Length, n = word2.Length;
            int[,] dp = new int[m + 1, n + 1];
            for (int i = 1; i <= m; i++)
            {
                char c1 = word1[i - 1];
                for (int j = 1; j <= n; j++)
                {
                    char c2 = word2[j - 1];
                    if (c1 == c2)
                    {
                        dp[i, j] = dp[i - 1, j - 1] + 1;
                    }
                    else
                    {
                        dp[i, j] = Math.Max(dp[i - 1, j], dp[i, j - 1]);
                    }
                }
            }

            int len = dp[m, n];
            return m + n - 2 * len;
        }
    }
}
