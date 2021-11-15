using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary.LC48
{
    /// <summary>
    /// 48. 旋转图像
    /// </summary>
    public class Class48
    {
        public void Rotate(int[][] matrix)
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
