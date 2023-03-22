﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1626
{
    public class Class1626
    {

        public int BestTeamScore(int[] scores, int[] ages)
        {
            int n = scores.Length;
            int[][] people = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                people[i] = new int[] { scores[i], ages[i] };
            }
            Array.Sort(people, (a, b) => a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
            int[] dp = new int[n];
            int res = 0;
            for (int i = 0; i < n; ++i)
            {
                for (int j = i - 1; j >= 0; --j)
                {
                    if (people[j][1] <= people[i][1])
                    {
                        dp[i] = Math.Max(dp[i], dp[j]);
                    }
                }
                dp[i] += people[i][0];
                res = Math.Max(res, dp[i]);
            }
            return res;
        }

    }
}
