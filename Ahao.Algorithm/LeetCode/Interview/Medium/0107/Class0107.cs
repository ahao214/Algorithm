using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Interview.Medium._0107
{
    /// <summary>
    /// 面试题 01.07. 旋转矩阵
    /// </summary>
    public class Class0107
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

        public void Rotate2(int[][] matrix)
        {
            var n = matrix.Length;
            var n1 = n - 1;
            for (int row = 0; row <= n / 2 - 1; row++)
            {
                for (int col = row; col < n - 1 - row; col++)
                {
                    var tmp = matrix[row][col];
                    matrix[row][col] = matrix[n1 - col][row];
                    matrix[n1 - col][row] = matrix[n1 - row][n1 - col];
                    matrix[n1 - row][n1 - col] = matrix[col][n1 - row];
                    matrix[col][n1 - row] = tmp;
                }
            }
        }

        public void Rotate3(int[][] matrix)
        {
            int tR = 0;
            int tC = 0;
            int dR = matrix.Length - 1;
            int dC = matrix[0].Length - 1;
            while (tR < dR)
            {
                RotateEdge(matrix, tR++, tC++, dR--, dC--);
            }
        }

        public void RotateEdge(int[][] m, int a, int b, int c, int d)
        {
            int times = d - b;  //一共多少组
            int tmp = 0;
            for (int i = 0; i < times; i++)
            {
                tmp = m[a][b + i];
                m[a][b + i] = m[c - i][b];
                m[c - i][b] = m[c][d - i];
                m[c][d - i] = m[a + i][d];
                m[a + i][d] = tmp;
            }
        }
    }
}
