using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1765
{
    /*
     1765. 地图中的最高点
给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。

如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
你需要按照如下规则给每个单元格安排高度：

每个格子的高度都必须是非负的。
如果一个格子是是 水域 ，那么它的高度必须为 0 。
任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。

请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。如果有多种解法，请返回 任意一个 。
     */
    public class Class1765
    {
        int[][] dirs = {new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { 0, 1 } };
        public int[][] HighestPeak(int[][] isWater)
        {
            int m = isWater.Length;
            int n = isWater[0].Length;
            int[][] res = new int[m][];
            for (int i = 0; i < m; i++)
            {
                res[i] = new int[n];
                Array.Fill(res[i], -1);
            }

            Queue<Tuple<int, int>> q = new Queue<Tuple<int, int>>();
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (isWater[i][j] == 1)
                    {
                        res[i][j] = 0;
                        q.Enqueue(new Tuple<int, int>(i, j));
                    }
                }
            }
            while (q.Count > 0)
            {
                Tuple<int, int> p = q.Dequeue();
                foreach (int[] dir in dirs)
                {
                    int x = p.Item1 + dir[0];
                    int y = p.Item2 + dir[1];
                    if (0 <= x && x < m && y >= 0 && y < n && res[x][y] == -1)
                    {
                        res[x][y] = res[p.Item1][p.Item2] + 1;
                        q.Enqueue(new Tuple<int, int>(x, y));
                    }
                }
            }
            return res;
        }
    }
}
