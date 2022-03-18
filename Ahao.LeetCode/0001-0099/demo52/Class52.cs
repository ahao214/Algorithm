using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo52
{
    /*
     52. N皇后 II
n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
     */
    public class Class52
    {
        public int TotalNQueens(int n)
        {
            var dp = new bool[n, n];
            var res = 0;
            FindP(0, 0);
            return res;

            void FindP(int y, int nums)
            {
                if (nums == n)
                {
                    res++;
                    return;
                }

                for (int x = 0; x < n; x++)
                {
                    if (CanP(x, y))
                    {
                        dp[y, x] = true;
                        FindP(y + 1, nums + 1);
                        dp[y, x] = false; // 撤销
                    }
                }
            }

            bool CanP(int x, int y)
            {
                // 上
                for (int i = y - 1; i >= 0; i--)
                    if (dp[i, x]) return false;
                // 左上
                for (int i = y - 1, j = x - 1; i >= 0 && j >= 0; i--, j--)
                    if (dp[i, j]) return false;
                // 右上
                for (int i = y - 1, j = x + 1; i >= 0 && j < n; i--, j++)
                    if (dp[i, j]) return false;

                return true;
            }
        }
    }

}
