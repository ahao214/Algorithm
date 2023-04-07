﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1040
{
    public class Class1040
    {
        public int[] NumMovesStonesII(int[] stones)
        {
            int n = stones.Length;
            Array.Sort(stones);
            if (stones[n - 1] - stones[0] + 1 == n)
            {
                return new int[] { 0, 0 };
            }
            int ma = Math.Max(stones[n - 2] - stones[0] + 1, stones[n - 1] - stones[1] + 1) - (n - 1);
            int mi = n;
            for (int i = 0, j = 0; i < n && j + 1 < n; ++i)
            {
                while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n)
                {
                    ++j;
                }
                if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1)
                {
                    mi = Math.Min(mi, 2);
                }
                else
                {
                    mi = Math.Min(mi, n - (j - i + 1));
                }
            }
            return new int[] { mi, ma };
        }


    }
}
