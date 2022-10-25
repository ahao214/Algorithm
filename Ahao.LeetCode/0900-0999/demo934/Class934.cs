﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo934
{
    public class Class934
    {
        /// <summary>
        /// 广度优先
        /// </summary>
        /// <param name="grid"></param>
        /// <returns></returns>
        public int ShortestBridge(int[][] grid)
        {
            int n = grid.Length;
            int[][] dirs = { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, 1 }, new int[] { 0, -1 } };
            IList<Tuple<int, int>> island = new List<Tuple<int, int>>();
            Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        queue.Enqueue(new Tuple<int, int>(i, j));
                        grid[i][j] = -1;
                        while (queue.Count > 0)
                        {
                            Tuple<int, int> cell = queue.Dequeue();
                            int x = cell.Item1, y = cell.Item2;
                            island.Add(cell);
                            for (int k = 0; k < 4; k++)
                            {
                                int nx = x + dirs[k][0];
                                int ny = y + dirs[k][1];
                                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1)
                                {
                                    queue.Enqueue(new Tuple<int, int>(nx, ny));
                                    grid[nx][ny] = -1;
                                }
                            }
                        }
                        foreach (Tuple<int, int> cell in island)
                        {
                            queue.Enqueue(cell);
                        }
                        int step = 0;
                        while (queue.Count > 0)
                        {
                            int sz = queue.Count;
                            for (int k = 0; k < sz; k++)
                            {
                                Tuple<int, int> cell = queue.Dequeue();
                                int x = cell.Item1, y = cell.Item2;
                                for (int d = 0; d < 4; d++)
                                {
                                    int nx = x + dirs[d][0];
                                    int ny = y + dirs[d][1];
                                    if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                                    {
                                        if (grid[nx][ny] == 0)
                                        {
                                            queue.Enqueue(new Tuple<int, int>(nx, ny));
                                            grid[nx][ny] = -1;
                                        }
                                        else if (grid[nx][ny] == 1)
                                        {
                                            return step;
                                        }
                                    }
                                }
                            }
                            step++;
                        }
                    }
                }
            }
            return 0;
        }




        public int ShortestBridge2(int[][] grid)
        {
            int n = grid.Length;
            int[][] dirs = { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, 1 }, new int[] { 0, -1 } };

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
                        DFS(i, j, grid, queue);
                        int step = 0;
                        while (queue.Count > 0)
                        {
                            int sz = queue.Count;
                            for (int k = 0; k < sz; k++)
                            {
                                Tuple<int, int> cell = queue.Dequeue();
                                int x = cell.Item1, y = cell.Item2;
                                for (int d = 0; d < 4; d++)
                                {
                                    int nx = x + dirs[d][0];
                                    int ny = y + dirs[d][1];
                                    if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                                    {
                                        if (grid[nx][ny] == 0)
                                        {
                                            queue.Enqueue(new Tuple<int, int>(nx, ny));
                                            grid[nx][ny] = -1;
                                        }
                                        else if (grid[nx][ny] == 1)
                                        {
                                            return step;
                                        }
                                    }
                                }
                            }
                            step++;
                        }
                    }
                }
            }
            return 0;
        }

        public void DFS(int x, int y, int[][] grid, Queue<Tuple<int, int>> queue)
        {
            if (x < 0 || y < 0 || x >= grid.Length || y >= grid[0].Length || grid[x][y] != 1)
            {
                return;
            }
            queue.Enqueue(new Tuple<int, int>(x, y));
            grid[x][y] = -1;
            DFS(x - 1, y, grid, queue);
            DFS(x + 1, y, grid, queue);
            DFS(x, y - 1, grid, queue);
            DFS(x, y + 1, grid, queue);
        }


    }
}
