﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1500_1599.demo1595
{
    public class Class1595
    {
        public int ConnectTwoGroups(IList<IList<int>> cost)
        {
            int size1 = cost.Count, size2 = cost[0].Count, m = 1 << size2;
            int[][] dp = new int[size1 + 1][];
            for (int i = 0; i <= size1; i++)
            {
                dp[i] = new int[m];
                Array.Fill(dp[i], int.MaxValue / 2);
            }
            dp[0][0] = 0;
            for (int i = 1; i <= size1; i++)
            {
                for (int s = 0; s < m; s++)
                {
                    for (int k = 0; k < size2; k++)
                    {
                        if ((s & (1 << k)) == 0)
                        {
                            continue;
                        }
                        dp[i][s] = Math.Min(dp[i][s], dp[i][s ^ (1 << k)] + cost[i - 1][k]);
                        dp[i][s] = Math.Min(dp[i][s], dp[i - 1][s] + cost[i - 1][k]);
                        dp[i][s] = Math.Min(dp[i][s], dp[i - 1][s ^ (1 << k)] + cost[i - 1][k]);
                    }
                }
            }
            return dp[size1][m - 1];
        }

    }
}
