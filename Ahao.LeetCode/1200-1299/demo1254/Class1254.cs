﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1254
{
    public class Class1254
    {

        static int[][] dir = { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { 0, 1 } };

        public int ClosedIsland(int[][] grid)
        {
            int m = grid.Length;
            int n = grid[0].Length;
            int ans = 0;

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 0)
                    {
                        Queue<Tuple<int, int>> qu = new Queue<Tuple<int, int>>();
                        grid[i][j] = 1;
                        bool closed = true;

                        qu.Enqueue(new Tuple<int, int>(i, j));
                        while (qu.Count > 0)
                        {
                            Tuple<int, int> tuple = qu.Dequeue();
                            int cx = tuple.Item1, cy = tuple.Item2;
                            if (cx == 0 || cy == 0 || cx == m - 1 || cy == n - 1)
                            {
                                closed = false;
                            }
                            for (int d = 0; d < 4; d++)
                            {
                                int nx = cx + dir[d][0];
                                int ny = cy + dir[d][1];
                                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0)
                                {
                                    grid[nx][ny] = 1;
                                    qu.Enqueue(new Tuple<int, int>(nx, ny));
                                }
                            }
                        }
                        if (closed)
                        {
                            ans++;
                        }
                    }
                }
            }
            return ans;
        }




        public int ClosedIsland2(int[][] grid)
        {
            int ans = 0;
            int m = grid.Length;
            int n = grid[0].Length;

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 0 && DFS(i, j, grid, m, n))
                    {
                        ans++;
                    }
                }
            }
            return ans;
        }

        public bool DFS(int x, int y, int[][] grid, int m, int n)
        {
            if (x < 0 || y < 0 || x >= m || y >= n)
            {
                return false;
            }
            if (grid[x][y] != 0)
            {
                return true;
            }
            grid[x][y] = -1;
            bool ret1 = DFS(x - 1, y, grid, m, n);
            bool ret2 = DFS(x + 1, y, grid, m, n);
            bool ret3 = DFS(x, y - 1, grid, m, n);
            bool ret4 = DFS(x, y + 1, grid, m, n);
            return ret1 && ret2 && ret3 && ret4;
        }

    }
}
