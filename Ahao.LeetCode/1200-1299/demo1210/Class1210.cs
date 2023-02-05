using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1210
{
    public class Class1210
    {

        public int MinimumMoves(int[][] grid)
        {
            int n = grid.Length;
            int[][][] dist = new int[n][][];
            for (int i = 0; i < n; i++)
            {
                dist[i] = new int[n][];
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = new int[2];
                    Array.Fill(dist[i][j], -1);
                }
            }
            dist[0][0][0] = 0;
            Queue<Tuple<int, int, int>> queue = new Queue<Tuple<int, int, int>>();
            queue.Enqueue(new Tuple<int, int, int>(0, 0, 0));

            while (queue.Count > 0)
            {
                Tuple<int, int, int> tuple = queue.Dequeue();
                int x = tuple.Item1, y = tuple.Item2, status = tuple.Item3;
                if (status == 0)
                {
                    // 向右移动一个单元格
                    if (y + 2 < n && dist[x][y + 1][0] == -1 && grid[x][y + 2] == 0)
                    {
                        dist[x][y + 1][0] = dist[x][y][0] + 1;
                        queue.Enqueue(new Tuple<int, int, int>(x, y + 1, 0));
                    }
                    // 向下移动一个单元格
                    if (x + 1 < n && dist[x + 1][y][0] == -1 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0)
                    {
                        dist[x + 1][y][0] = dist[x][y][0] + 1;
                        queue.Enqueue(new Tuple<int, int, int>(x + 1, y, 0));
                    }
                    // 顺时针旋转 90 度
                    if (x + 1 < n && y + 1 < n && dist[x][y][1] == -1 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0)
                    {
                        dist[x][y][1] = dist[x][y][0] + 1;
                        queue.Enqueue(new Tuple<int, int, int>(x, y, 1));
                    }
                }
                else
                {
                    // 向右移动一个单元格
                    if (y + 1 < n && dist[x][y + 1][1] == -1 && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0)
                    {
                        dist[x][y + 1][1] = dist[x][y][1] + 1;
                        queue.Enqueue(new Tuple<int, int, int>(x, y + 1, 1));
                    }
                    // 向下移动一个单元格
                    if (x + 2 < n && dist[x + 1][y][1] == -1 && grid[x + 2][y] == 0)
                    {
                        dist[x + 1][y][1] = dist[x][y][1] + 1;
                        queue.Enqueue(new Tuple<int, int, int>(x + 1, y, 1));
                    }
                    // 逆时针旋转 90 度
                    if (x + 1 < n && y + 1 < n && dist[x][y][0] == -1 && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0)
                    {
                        dist[x][y][0] = dist[x][y][1] + 1;
                        queue.Enqueue(new Tuple<int, int, int>(x, y, 0));
                    }
                }
            }

            return dist[n - 1][n - 2][0];
        }
    }
}
