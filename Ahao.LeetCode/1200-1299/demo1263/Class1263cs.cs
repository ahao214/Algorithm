using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1263
{
    public class Class1263cs
    {

        public int MinPushBox(char[][] grid)
        {
            int m = grid.Length, n = grid[0].Length;
            int sx = -1, sy = -1, bx = -1, by = -1; // 玩家、箱子的初始位置
            for (int x = 0; x < m; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    if (grid[x][y] == 'S')
                    {
                        sx = x;
                        sy = y;
                    }
                    else if (grid[x][y] == 'B')
                    {
                        bx = x;
                        by = y;
                    }
                }
            }

            int[] d = { 0, -1, 0, 1, 0 };

            int[][] dp = new int[m * n][];
            for (int i = 0; i < m * n; i++)
            {
                dp[i] = new int[m * n];
                Array.Fill(dp[i], int.MaxValue);
            }
            Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
            dp[sx * n + sy][bx * n + by] = 0; // 初始状态的推动次数为 0
            queue.Enqueue(new Tuple<int, int>(sx * n + sy, bx * n + by));
            while (queue.Count > 0)
            {
                Queue<Tuple<int, int>> queue1 = new Queue<Tuple<int, int>>();
                while (queue.Count > 0)
                {
                    Tuple<int, int> tuple = queue.Dequeue();
                    int s1 = tuple.Item1, b1 = tuple.Item2;
                    int sx1 = s1 / n, sy1 = s1 % n, bx1 = b1 / n, by1 = b1 % n;
                    if (grid[bx1][by1] == 'T')
                    { // 箱子已被推到目标处
                        return dp[s1][b1];
                    }
                    for (int i = 0; i < 4; i++)
                    { // 玩家向四个方向移动到另一个状态
                        int sx2 = sx1 + d[i], sy2 = sy1 + d[i + 1], s2 = sx2 * n + sy2;
                        if (!Ok(grid, m, n, sx2, sy2))
                        { // 玩家位置不合法
                            continue;
                        }
                        if (bx1 == sx2 && by1 == sy2)
                        { // 推动箱子
                            int bx2 = bx1 + d[i], by2 = by1 + d[i + 1], b2 = bx2 * n + by2;
                            if (!Ok(grid, m, n, bx2, by2) || dp[s2][b2] <= dp[s1][b1] + 1)
                            { // 箱子位置不合法 或 状态已访问
                                continue;
                            }
                            dp[s2][b2] = dp[s1][b1] + 1;
                            queue1.Enqueue(new Tuple<int, int>(s2, b2));
                        }
                        else
                        {
                            if (dp[s2][b1] <= dp[s1][b1])
                            { // 状态已访问
                                continue;
                            }
                            dp[s2][b1] = dp[s1][b1];
                            queue.Enqueue(new Tuple<int, int>(s2, b1));
                        }
                    }
                }
                queue = queue1;
            }
            return -1;
        }

        public bool Ok(char[][] grid, int m, int n, int x, int y)
        { // 不越界且不在墙上
            return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
        }


    }
}
