using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo130
{
    /// <summary>
    /// 130. 被围绕的区域
    /// </summary>
    public class Class130
    {
        int row, col;
        public void Solve(char[][] board)
        {
            row = board.Length;
            if (row == 0)
            {
                return;
            }

            col = board[0].Length;
            for (int i = 0; i < row; ++i)
            {
                dfs(board, i, 0);
                dfs(board, i, col - 1);
            }
            for (int i = 1; i < col - 1; ++i)
            {
                dfs(board, 0, i);
                dfs(board, row - 1, i);
            }
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    if (board[i][j] == '#')
                    {
                        board[i][j] = 'O';
                    }
                    else if (board[i][j] == 'O')
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }

        public void dfs(char[][] board, int x, int y)
        {
            if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] != 'O')
            {
                return;
            }
            board[x][y] = '#';
            dfs(board, x + 1, y);
            dfs(board, x - 1, y);
            dfs(board, x, y + 1);
            dfs(board, x, y - 1);
        }
    }
}
