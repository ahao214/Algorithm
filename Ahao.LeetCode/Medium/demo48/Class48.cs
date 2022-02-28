using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo48
{
    /*
     48. 旋转图像
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
     */
    public class Class48
    {
        public void Rotate(int[][] matrix)
        {
            var n = matrix.Length;
            for (int row = 0; row <= n / 2 - 1; row++)
            {
                var tmp = matrix[row];
                matrix[row] = matrix[n - 1 - row];
                matrix[n - 1 - row] = tmp;
            }
            for (int row = 0; row < n; row++)
            {
                for (int col = row + 1; col < n; col++)
                {
                    var tmp = matrix[row][col];
                    matrix[row][col] = matrix[col][row];
                    matrix[col][row] = tmp;
                }
            }
        }
    }
}
