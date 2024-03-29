﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    public class Class2132
    {
        public bool PossibleToStamp(int[][] grid, int stampHeight, int stampWidth)
        {
            int m = grid.Length, n = grid[0].Length;
            int[][] sum = new int[m + 2][];
            int[][] diff = new int[m + 2][];
            for (int i = 0; i < m + 2; i++)
            {
                sum[i] = new int[n + 2];
                diff[i] = new int[n + 2];
            }
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i - 1][j - 1];
                }
            }

            for (int i = 1; i + stampHeight - 1 <= m; i++)
            {
                for (int j = 1; j + stampWidth - 1 <= n; j++)
                {
                    int x = i + stampHeight - 1;
                    int y = j + stampWidth - 1;
                    if (sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1] == 0)
                    {
                        diff[i][j]++;
                        diff[i][y + 1]--;
                        diff[x + 1][j]--;
                        diff[x + 1][y + 1]++;
                    }
                }
            }

            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                    if (diff[i][j] == 0 && grid[i - 1][j - 1] == 0)
                    {
                        return false;
                    }
                }
            }
            return true;
        }


    }
}
