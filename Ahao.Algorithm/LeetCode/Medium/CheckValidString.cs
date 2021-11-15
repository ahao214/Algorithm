﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 678. 有效的括号字符串
    /// </summary>
    public class CheckValidString
    {
        public bool Method(string s)
        {
            int n = s.Length;
            bool[,] dp = new bool[n, n];
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '*')
                {
                    dp[i, i] = true;
                }
            }
            for (int i = 1; i < n; i++)
            {
                char c1 = s[i - 1], c2 = s[i];
                dp[i - 1, i] = (c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*');
            }
            for (int i = n - 3; i >= 0; i--)
            {
                char c1 = s[i];
                for (int j = i + 2; j < n; j++)
                {
                    char c2 = s[j];
                    if ((c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*'))
                    {
                        dp[i, j] = dp[i + 1, j - 1];
                    }
                    for (int k = i; k < j && !dp[i, j]; k++)
                    {
                        dp[i, j] = dp[i, k] && dp[k + 1, j];
                    }
                }
            }
            return dp[0, n - 1];
        }
    }
}




