using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1020
{
    /*
     1020. 飞地的数量
给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。

一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。

返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
     */
    public class Class1020
    {
        public static int[][] dirs = { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { 0, 1 } };
        private int m, n;
        private bool[][] visited;
        public int NumEnclaves(int[][] grid)
        {
            m = grid.Length;
            n = grid[0].Length;
            visited = new bool[m][];
            for (int i = 0; i < m; i++)
            {
                visited[i] = new bool[n];
            }
            for (int i = 0; i < m; i++)
            {
                //第一列
                DFS(grid, i, 0);
                //最后一列
                DFS(grid, i, n - 1);
            }

            for (int j = 1; j < n - 1; j++)
            {
                //第一行
                DFS(grid, 0, j);
                //最后一行
                DFS(grid, m - 1, j);
            }
            int res = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1 && !visited[i][j])
                    {
                        res++;
                    }
                }
            }
            return res;
        }

        private void DFS(int[][] grid, int row, int col)
        {
            if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0 || visited[row][col])
            {
                return;
            }
            visited[row][col] = true;
            foreach (int[] dir in dirs)
            {
                DFS(grid, row + dir[0], col + dir[1]);
            }
        }

    }
}
