﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 516. 最长回文子序列
    /// </summary>
    public class LongestPalindromeSubseq
    {
        public int Method(string s)
        {
            int n = s.Length;
            int[,] dp = new int[n, n];
            for (int i = n - 1; i >= 0; i--)
            {
                dp[i, i] = 1;
                char c1 = s[i];
                for (int j = i + 1; j < n; j++)
                {
                    char c2 = s[j];
                    if (c1 == c2)
                    {
                        dp[i, j] = dp[i + 1, j - 1] + 2;
                    }
                    else
                    {
                        dp[i, j] = Math.Max(dp[i + 1, j], dp[i, j - 1]);
                    }
                }
            }
            return dp[0, n - 1];


        }
    }
}
