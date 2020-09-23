using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 79.单词搜索
    /// </summary>
    public class Exist
    {
        public bool answer = false;
        public bool Method(char[][] board, string word)
        {
            int row = board.GetLength(0);
            int col = board[0].GetLength(0);
            bool[,] used = new bool[row, col];
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (board[i][j] == word[0])
                    {
                        dfs(i, j, row, col, board, word, 0, used);
                    }
                }
            }
            return answer;
        }

       
        public void dfs(int i, int j, int row, int col, char[][] board, string word, int index, bool[,] used)
        {
            if (answer == true)  //已经有满足条件的了  不再递归 必须要加这个不然会超时
            {
                return;
            }
            if (index == word.Length)
            {
                answer = true;
                return;
            }
            if (i < 0 || i > row - 1 || j < 0 || j > col - 1 || used[i, j] == true || board[i][j] != word[index])
            {
                return;
            }
            //做出选择
            used[i, j] = true;
            //递归
            dfs(i - 1, j, row, col, board, word, index + 1, used);
            dfs(i + 1, j, row, col, board, word, index + 1, used);
            dfs(i, j - 1, row, col, board, word, index + 1, used);
            dfs(i, j + 1, row, col, board, word, index + 1, used);
            //取消选择
            used[i, j] = false;
        }
    }

   

   
}
