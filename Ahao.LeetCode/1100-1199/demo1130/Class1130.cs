﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1130
{
    public class Class1130
    {
        public int MctFromLeafValues(int[] arr)
        {
            int n = arr.Length;
            int[][] dp = new int[n][];
            for (int i = 0; i < n; i++)
            {
                dp[i] = new int[n];
                Array.Fill(dp[i], int.MaxValue / 4);
            }
            int[][] mval = new int[n][];
            for (int i = 0; i < n; i++)
            {
                mval[i] = new int[n];
            }
            for (int j = 0; j < n; j++)
            {
                mval[j][j] = arr[j];
                dp[j][j] = 0;
                for (int i = j - 1; i >= 0; i--)
                {
                    mval[i][j] = Math.Max(arr[i], mval[i + 1][j]);
                    for (int k = i; k < j; k++)
                    {
                        dp[i][j] = Math.Min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]);
                    }
                }
            }
            return dp[0][n - 1];
        }


    }
}
