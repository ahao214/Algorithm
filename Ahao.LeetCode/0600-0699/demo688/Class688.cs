using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo688
{
    /*
688. 骑士在棋盘上的概率
在一个 n x n 的国际象棋棋盘上，一个骑士从单元格
 (row, column) 开始，并尝试进行 k 次移动。
 行和列是 从 0 开始 的，所以左上单元格是 (0,0) ，右下单元格是 (n - 1, n - 1) 。

象棋骑士有8种可能的走法，如下图所示。
每次移动在基本方向上是两个单元格，
然后在正交方向上是一个单元格。

每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。

骑士继续移动，直到它走了 k 步或离开了棋盘。
返回 骑士在棋盘停止移动后仍留在棋盘上的概率 。
*/
    public class Class688
    {
        public double KnightProbability(int n, int k, int row, int column)
        {
            int[][] dirs = { new int[] { -2, 1 }, new int[] { -2, -1 }, new int[] { 2, 1 }, new int[] { 2, -1 }, new int[] { 1, 2 }, new int[] { 1, -2 }, new int[] { -1, -2 }, new int[] { -1, 2 } };

            double[,,] dp = new double[k + 1, n, n];
            for (int step = 0; step <= k; step++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        //走完K步
                        if (step == 0)
                        {
                            dp[step, i, j] = 1;
                        }
                        else
                        {
                            foreach (var dir in dirs)
                            {
                                int dx = i + dir[0], dy = j + dir[1];
                                if (dx >= 0 && dx < n && dy >= 0 && dy < n)
                                    dp[step, i, j] += dp[step - 1, dx, dy] / 8;
                            }
                        }
                    }
                }
            }
            return dp[k, row, column];
        }
    }
}
