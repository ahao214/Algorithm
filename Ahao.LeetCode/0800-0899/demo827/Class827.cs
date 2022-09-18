﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo827
{
    public class Class827
    {

        static int[] d = { 0, -1, 0, 1, 0 };

        public int LargestIsland(int[][] grid)
        {
            int n = grid.Length, res = 0;
            int[][] tag = new int[n][];
            for (int i = 0; i < n; i++)
            {
                tag[i] = new int[n];
            }
            Dictionary<int, int> area = new Dictionary<int, int>();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1 && tag[i][j] == 0)
                    {
                        int t = i * n + j + 1;
                        area.Add(t, DFS(grid, i, j, tag, t));
                        res = Math.Max(res, area[t]);
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 0)
                    {
                        int z = 1;
                        ISet<int> connected = new HashSet<int>();
                        for (int k = 0; k < 4; k++)
                        {
                            int x = i + d[k], y = j + d[k + 1];
                            if (!Valid(n, x, y) || tag[x][y] == 0 || connected.Contains(tag[x][y]))
                            {
                                continue;
                            }
                            z += area[tag[x][y]];
                            connected.Add(tag[x][y]);
                        }
                        res = Math.Max(res, z);
                    }
                }
            }
            return res;
        }

        public int DFS(int[][] grid, int x, int y, int[][] tag, int t)
        {
            int n = grid.Length, res = 1;
            tag[x][y] = t;
            for (int i = 0; i < 4; i++)
            {
                int x1 = x + d[i], y1 = y + d[i + 1];
                if (Valid(n, x1, y1) && grid[x1][y1] == 1 && tag[x1][y1] == 0)
                {
                    res += DFS(grid, x1, y1, tag, t);
                }
            }
            return res;
        }

        public bool Valid(int n, int x, int y)
        {
            return x >= 0 && x < n && y >= 0 && y < n;
        }
    }
}
