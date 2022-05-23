﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo675
{
    public class Class675
    {

        int[][] dirs = { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { 0, 1 } };

        public int CutOffTree(IList<IList<int>> forest)
        {
            List<Tuple<int, int>> trees = new List<Tuple<int, int>>();
            int row = forest.Count;
            int col = forest[0].Count;
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    if (forest[i][j] > 1)
                    {
                        trees.Add(new Tuple<int, int>(i, j));
                    }
                }
            }
            trees.Sort((a, b) => forest[a.Item1][a.Item2] - forest[b.Item1][b.Item2]);

            int cx = 0;
            int cy = 0;
            int ans = 0;
            for (int i = 0; i < trees.Count; ++i)
            {
                int steps = BFS(forest, cx, cy, trees[i].Item1, trees[i].Item2);
                if (steps == -1)
                {
                    return -1;
                }
                ans += steps;
                cx = trees[i].Item1;
                cy = trees[i].Item2;
            }
            return ans;
        }

        public int BFS(IList<IList<int>> forest, int sx, int sy, int tx, int ty)
        {
            if (sx == tx && sy == ty)
            {
                return 0;
            }

            int row = forest.Count;
            int col = forest[0].Count;
            int step = 0;
            Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
            bool[,] visited = new bool[row, col];
            queue.Enqueue(new Tuple<int, int>(sx, sy));
            visited[sx, sy] = true;
            while (queue.Count > 0)
            {
                step++;
                int sz = queue.Count;
                for (int i = 0; i < sz; ++i)
                {
                    Tuple<int, int> cell = queue.Dequeue();
                    int cx = cell.Item1, cy = cell.Item2;
                    for (int j = 0; j < 4; ++j)
                    {
                        int nx = cx + dirs[j][0];
                        int ny = cy + dirs[j][1];
                        if (nx >= 0 && nx < row && ny >= 0 && ny < col)
                        {
                            if (!visited[nx, ny] && forest[nx][ny] > 0)
                            {
                                if (nx == tx && ny == ty)
                                {
                                    return step;
                                }
                                queue.Enqueue(new Tuple<int, int>(nx, ny));
                                visited[nx, ny] = true;
                            }
                        }
                    }
                }
            }
            return -1;
        }


    }
}
