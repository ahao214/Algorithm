﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1326
{
    public class Class1326
    {
        /// <summary>
        /// 动态规划
        /// </summary>
        /// <param name="n"></param>
        /// <param name="ranges"></param>
        /// <returns></returns>
        public int MinTaps(int n, int[] ranges)
        {
            int[][] intervals = new int[n + 1][];
            for (int i = 0; i <= n; i++)
            {
                int start = Math.Max(0, i - ranges[i]);
                int end = Math.Min(n, i + ranges[i]);
                intervals[i] = new int[] { start, end };
            }
            Array.Sort(intervals, (a, b) => a[0] - b[0]);
            int[] dp = new int[n + 1];
            Array.Fill(dp, int.MaxValue);
            dp[0] = 0;
            foreach (int[] interval in intervals)
            {
                int start = interval[0], end = interval[1];
                if (dp[start] == int.MaxValue)
                {
                    return -1;
                }
                for (int j = start; j <= end; j++)
                {
                    dp[j] = Math.Min(dp[j], dp[start] + 1);
                }
            }
            return dp[n];
        }

    }
}
