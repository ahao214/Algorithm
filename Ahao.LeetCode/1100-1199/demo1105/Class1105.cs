﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1105
{
    public class Class1105
    {
        public int MinHeightShelves(int[][] books, int shelfWidth)
        {
            int n = books.Length;
            int[] dp = new int[n + 1];
            Array.Fill(dp, 1000000);
            dp[0] = 0;
            for (int i = 0; i < n; ++i)
            {
                int maxHeight = 0, curWidth = 0;
                for (int j = i; j >= 0; --j)
                {
                    curWidth += books[j][0];
                    if (curWidth > shelfWidth)
                    {
                        break;
                    }
                    maxHeight = Math.Max(maxHeight, books[j][1]);
                    dp[i + 1] = Math.Min(dp[i + 1], dp[j] + maxHeight);
                }
            }
            return dp[n];
        }


    }
}
