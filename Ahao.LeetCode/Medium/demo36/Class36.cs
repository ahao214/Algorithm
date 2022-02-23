using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo36
{
    /*
     36. 有效的数独
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
     */
    public class Class36
    {
        public bool IsValidSudoku(char[][] board)
        {
            int[,] rows = new int[9, 9];
            int[,] cols = new int[9, 9];
            int[,,] boxes = new int[3, 3, 9];
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    char c = board[i][j];
                    if (c != '.')
                    {
                        int index = c - '0' - 1;
                        rows[i, index]++;
                        cols[j, index]++;
                        boxes[i / 3, j / 3, index]++;
                        if (rows[i, index] > 1 || cols[j, index] > 1 || boxes[i / 3, j / 3, index] > 1)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
    }
}
