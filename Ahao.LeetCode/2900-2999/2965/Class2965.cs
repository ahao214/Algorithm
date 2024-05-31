﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2900_2999._2965
{
    internal class Class2965
    {

        public int[] FindMissingAndRepeatedValues(int[][] grid)
        {
            int n = grid.Length;
            int[] count = new int[n * n + 1];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    count[grid[i][j]]++;
                }
            }

            int[] res = new int[2];
            for (int i = 1; i <= n * n; i++)
            {
                if (count[i] == 2)
                {
                    res[0] = i;
                }
                if (count[i] == 0)
                {
                    res[1] = i;
                }
            }
            return res;
        }

    }
}
