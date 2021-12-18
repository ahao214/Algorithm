using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo419
{
    /// <summary>
    /// 419.甲板上的战舰
    /// </summary>
    public class Class419
    {
        //方法一：遍历扫描
        public int CountBattleships(char[][] board)
        {
            int row = board.Length;
            int col = board[0].Length;
            int ans = 0;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (board[i][j] == 'X')
                    {
                        board[i][j] = '.';
                        for (int k = j + 1; k < col && board[i][k] == 'X'; ++k)
                        {
                            board[i][k] = '.';
                        }
                        for (int k = i + 1; k < row && board[k][j] == 'X'; ++k)
                        {
                            board[k][j] = '.';
                        }
                        ans++;
                    }
                }
            }
            return ans;
        }
    }
}
