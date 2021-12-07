﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1034
{
    /// <summary>
    /// 1034. 边界着色
    /// </summary>
    public class Class1034
    {
        /// <summary>
        /// 深度优先
        /// </summary>
        /// <param name="grid"></param>
        /// <param name="row"></param>
        /// <param name="col"></param>
        /// <param name="color"></param>
        /// <returns></returns>
        public int[][] ColorBorder(int[][] grid, int row, int col, int color)
        {
            int m = grid.Length;
            int n = grid[0].Length;
            bool[,] visited = new bool[m, n];
            IList<int[]> borders = new List<int[]>();
            int originalColor = grid[row][col];
            visited[row, col] = true;
            DFS(grid, row, col, visited, borders, originalColor);
            for (int i = 0; i < borders.Count; i++)
            {
                int x = borders[i][0];
                int y = borders[i][1];
                grid[x][y] = color;
            }
            return grid;
        }

        private void DFS(int[][] grid, int x, int y, bool[,] visited, IList<int[]> borders, int originalColor)
        {
            int m = grid.Length;
            int n = grid[0].Length;
            bool isBorder = false;
            int[][] direc = { new int[] { 0, 1 }, new int[] { 0, -1 }, new int[] { 1, 0 }, new int[] { -1, 0 } };
            for (int i = 0; i < 4; i++)
            {
                int nx = direc[i][0] + x;
                int ny = direc[i][1] + y;
                if (!(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == originalColor))
                {
                    isBorder = true;
                }
                else if (!visited[nx, ny])
                {
                    visited[nx, ny] = true;
                    DFS(grid, nx, ny, visited, borders, originalColor);
                }
            }
            if (isBorder)
            {
                borders.Add(new int[] { x, y });
            }
        }

        /// <summary>
        /// 广度优先
        /// </summary>
        /// <param name="grid"></param>
        /// <param name="row"></param>
        /// <param name="col"></param>
        /// <param name="color"></param>
        /// <returns></returns>
        public int[][] ColorBorder2(int[][] grid, int row, int col, int color)
        {
            int m = grid.Length;
            int n = grid[0].Length;
            bool[,] visited = new bool[m, n];
            IList<int[]> borders = new List<int[]>();
            int originalColor = grid[row][col];
            int[][] direc = { new int[] { 0, 1 }, new int[] { 0, -1 }, new int[] { 1, 0 }, new int[] { -1, 0 } };
            Queue<int[]> q = new Queue<int[]>();
            visited[row, col] = true;
            q.Enqueue(new int[] { row, col });
            while (q.Count > 0)
            {
                int[] node = q.Dequeue();
                int x = node[0];
                int y = node[1];
                bool isBorder = false;
                for (int i = 0; i < 4; i++)
                {
                    int nx = direc[i][0] + x;
                    int ny = direc[i][1] + y;
                    if (!(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx)[ny] == originalColor))
                    {
                        isBorder = true;
                    }
                    else if (!visited[nx, ny])
                    {
                        visited[nx, ny] = true;
                        q.Enqueue(new int[] { nx, ny });
                    }
                }
                if (isBorder)
                {
                    borders.Add(new int[] { x, y });
                }
            }
            for (int i = 0; i < borders.Count; i++)
            {
                int x = borders[i][0];
                int y = borders[i][1];
                grid[x][y] = color;
            }
            return grid;
        }
    }
}
