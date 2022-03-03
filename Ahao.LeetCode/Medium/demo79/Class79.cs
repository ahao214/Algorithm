using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo79
{
    /*
     79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
     */
    public class Class79
    {
        public bool answer = false;
        public bool Exist(char[][] board, string word)
        {
            int row = board.GetLength(0);
            int col = board[0].GetLength(0);
            bool[,] used = new bool[row, col];
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                    if (board[i][j] == word[0])
                        Method(i, j, row, col, board, word, 0, used);
            }
            return answer;
        }

        public void Method(int i, int j, int row, int col, char[][] board, string word, int index, bool[,] used)
        {
            if (answer == true)  //已经有满足条件的了  不再递归 必须要加这个不然会超时            
                return;
            if (index == word.Length)
            {
                answer = true;
                return;
            }
            if (i < 0 || i > row - 1 || j < 0 || j > col - 1 || used[i, j] == true || board[i][j] != word[index])
                return;

            //做出选择
            used[i, j] = true;
            //递归
            Method(i - 1, j, row, col, board, word, index + 1, used);
            Method(i + 1, j, row, col, board, word, index + 1, used);
            Method(i, j - 1, row, col, board, word, index + 1, used);
            Method(i, j + 1, row, col, board, word, index + 1, used);
            //取消选择
            used[i, j] = false;
        }

    }
}
