using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo289
{
    public class Class289
    {
        public void GameOfLife(int[][] board)
        {
            int n = board.Length;
            int m = board[0].Length;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int ns = neighbors(board, i, j);
                    if (ns == 3 || (board[i][j] == 1 && ns == 2))
                    {
                        board[i][j] |= 2;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    board[i][j] >>= 1;
                }
            }
        }

        public int neighbors(int[][] board, int i, int j)
        {
            return f(board, i - 1, j - 1)
                    + f(board, i - 1, j)
                    + f(board, i - 1, j + 1)
                    + f(board, i, j - 1)
                    + f(board, i, j + 1)
                    + f(board, i + 1, j - 1)
                    + f(board, i + 1, j)
                    + f(board, i + 1, j + 1);
        }

        //board[i][j]上有1返回1，不是1就返回0
        public int f(int[][] board, int i, int j)
        {
            return (i >= 0 && i < board.Length && j >= 0 && j < board[0].Length && (board[i][j] & 1) == 1) ? 1 : 0;
        }


    }
}
