﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo902
{
    public class Class902
    {
        public int AtMostNGivenDigitSet(string[] digits, int n)
        {
            string s = n.ToString();
            int m = digits.Length, k = s.Length;
            int[][] dp = new int[k + 1][];
            for (int i = 0; i <= k; i++)
            {
                dp[i] = new int[2];
            }
            dp[0][1] = 1;
            for (int i = 1; i <= k; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (digits[j][0] == s[i - 1])
                    {
                        dp[i][1] = dp[i - 1][1];
                    }
                    else if (digits[j][0] < s[i - 1])
                    {
                        dp[i][0] += dp[i - 1][1];
                    }
                    else
                    {
                        break;
                    }
                }
                if (i > 1)
                {
                    dp[i][0] += m + dp[i - 1][0] * m;
                }
            }
            return dp[k][0] + dp[k][1];
        }
    }
}
