using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo59
{
    /*
     59. 螺旋矩阵 II
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
     */
    public class Class59
    {
        public int[][] GenerateMatrix(int n)
        {
            var step = new (int row, int col)[] { (0, 1), (1, 0), (0, -1), (-1, 0) };

            var k = 0;
            var (row, col) = (0, 0);
            var matrix = new int[n][];
            for (int i = 0; i < n; i++)
            {
                matrix[i] = new int[n];
            }
            for (int i = 1; i <= n * n; i++)
            {
                matrix[row][col] = i;
                var r1 = row + step[k].row;
                var c1 = col + step[k].col;
                if (r1 < 0 || r1 >= n || c1 >= n || c1 < 0 || matrix[r1][c1] != 0)
                {
                    k = (k + 1) % step.Length;
                }
                row += step[k].row;
                col += step[k].col;
            }
            return matrix;
        }
    }
}
