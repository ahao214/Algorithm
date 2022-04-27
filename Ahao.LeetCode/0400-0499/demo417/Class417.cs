﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo417
{
    public class Class417
    {
        //深度优先
        static int[][] dirs = { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { 0, 1 } };
        int[][] heights;
        int m, n;

        public IList<IList<int>> PacificAtlantic(int[][] heights)
        {
            this.heights = heights;
            this.m = heights.Length;
            this.n = heights[0].Length;
            bool[][] pacific = new bool[m][];
            bool[][] atlantic = new bool[m][];
            for (int i = 0; i < m; i++)
            {
                pacific[i] = new bool[n];
                atlantic[i] = new bool[n];
            }
            for (int i = 0; i < m; i++)
            {
                DFS(i, 0, pacific);
            }
            for (int j = 1; j < n; j++)
            {
                DFS(0, j, pacific);
            }
            for (int i = 0; i < m; i++)
            {
                DFS(i, n - 1, atlantic);
            }
            for (int j = 0; j < n - 1; j++)
            {
                DFS(m - 1, j, atlantic);
            }
            IList<IList<int>> result = new List<IList<int>>();
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (pacific[i][j] && atlantic[i][j])
                    {
                        IList<int> cell = new List<int>();
                        cell.Add(i);
                        cell.Add(j);
                        result.Add(cell);
                    }
                }
            }
            return result;
        }

        public void DFS(int row, int col, bool[][] ocean)
        {
            if (ocean[row][col])
            {
                return;
            }
            ocean[row][col] = true;
            foreach (int[] dir in dirs)
            {
                int newRow = row + dir[0], newCol = col + dir[1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col])
                {
                    DFS(newRow, newCol, ocean);
                }
            }
        }


        //广度优先

        public IList<IList<int>> PacificAtlantic1(int[][] heights)
        {
            this.heights = heights;
            this.m = heights.Length;
            this.n = heights[0].Length;
            bool[][] pacific = new bool[m][];
            bool[][] atlantic = new bool[m][];
            for (int i = 0; i < m; i++)
            {
                pacific[i] = new bool[n];
                atlantic[i] = new bool[n];
            }
            for (int i = 0; i < m; i++)
            {
                BFS(i, 0, pacific);
            }
            for (int j = 1; j < n; j++)
            {
                BFS(0, j, pacific);
            }
            for (int i = 0; i < m; i++)
            {
                BFS(i, n - 1, atlantic);
            }
            for (int j = 0; j < n - 1; j++)
            {
                BFS(m - 1, j, atlantic);
            }
            IList<IList<int>> result = new List<IList<int>>();
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (pacific[i][j] && atlantic[i][j])
                    {
                        IList<int> cell = new List<int>();
                        cell.Add(i);
                        cell.Add(j);
                        result.Add(cell);
                    }
                }
            }
            return result;
        }

        public void BFS(int row, int col, bool[][] ocean)
        {
            if (ocean[row][col])
            {
                return;
            }
            ocean[row][col] = true;
            Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
            queue.Enqueue(new Tuple<int, int>(row, col));
            while (queue.Count > 0)
            {
                Tuple<int, int> cell = queue.Dequeue();
                foreach (int[] dir in dirs)
                {
                    int newRow = cell.Item1 + dir[0], newCol = cell.Item2 + dir[1];
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[cell.Item1][cell.Item2] && !ocean[newRow][newCol])
                    {
                        ocean[newRow][newCol] = true;
                        queue.Enqueue(new Tuple<int, int>(newRow, newCol));
                    }
                }
            }
        }

    }
}
