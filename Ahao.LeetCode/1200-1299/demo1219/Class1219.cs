﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1219
{
    public class Class1219
    {
        static int[][] dirs = { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { 0, 1 } };
        int[][] grid;
        int m, n;
        int ans = 0;

        public int GetMaximumGold(int[][] grid)
        {
            this.grid = grid;
            this.m = grid.Length;
            this.n = grid[0].Length;
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (grid[i][j] != 0)
                    {
                        DFS(i, j, 0);
                    }
                }
            }
            return ans;
        }

        public void DFS(int x, int y, int gold)
        {
            gold += grid[x][y];
            ans = Math.Max(ans, gold);

            int rec = grid[x][y];
            grid[x][y] = 0;

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0)
                {
                    DFS(nx, ny, gold);
                }
            }

            grid[x][y] = rec;
        }

    }
}
