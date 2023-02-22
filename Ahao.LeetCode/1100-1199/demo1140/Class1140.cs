﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1140
{
    public class Class1140
    {

        public int StoneGameII(int[] piles)
        {
            int[] prefixSum = new int[piles.Length + 1];
            for (int i = 0; i < piles.Length; i++)
            {
                prefixSum[i + 1] = prefixSum[i] + piles[i];
            }

            IDictionary<int, int> memo = new Dictionary<int, int>();
            return (prefixSum[piles.Length] + DP(memo, piles, prefixSum, 0, 1)) / 2;
        }

        public int DP(IDictionary<int, int> memo, int[] piles, int[] prefixSum, int i, int m)
        {
            if (i == piles.Length)
            {
                return 0;
            }
            int key = i * 201 + m;
            if (!memo.ContainsKey(key))
            {
                int maxVal = int.MinValue;
                for (int x = 1; x <= 2 * m; x++)
                {
                    if (i + x > piles.Length)
                    {
                        break;
                    }
                    maxVal = Math.Max(maxVal, prefixSum[i + x] - prefixSum[i] - DP(memo, piles, prefixSum, i + x, Math.Max(m, x)));
                }
                memo.Add(key, maxVal);
            }
            return memo[key];
        }


    }
}
