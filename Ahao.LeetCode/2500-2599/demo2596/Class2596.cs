﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2596
{
    internal class Class2582
    {
        public bool CheckValidGrid(int[][] grid)
        {
            if (grid[0][0] != 0)
            {
                return false;
            }
            int n = grid.Length;
            int[][] indices = new int[n * n][];
            for (int i = 0; i < n * n; i++)
            {
                indices[i] = new int[2];
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    indices[grid[i][j]][0] = i;
                    indices[grid[i][j]][1] = j;
                }
            }
            for (int i = 1; i < n * n; i++)
            {
                int dx = Math.Abs(indices[i][0] - indices[i - 1][0]);
                int dy = Math.Abs(indices[i][1] - indices[i - 1][1]);
                if (dx * dy != 2)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
