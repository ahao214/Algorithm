using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 对数组进行旋转
    /// </summary>
    public class TestRotate
    {
        public void Rotate(int[][] matrix)
        {
            int n = matrix.Length;
            int[][] m = new int[n][];
            for (int row = 0; row < n; row++)
            {
                for (int col = 0; col < n; col++)
                {
                    m[row][col] = matrix[n - 1 - col][row];
                }
            }

            //再赋值会matrix，注意形参是引用传递
            for (int row = 0; row < n; row++)
            {
                for (int col = 0; col < n; col++)
                {
                    matrix[row][col] = m[row][col];
                }
            }
        }

        public void Rotate2(int[][] matrix)
        {
            int n = matrix.Length;
            int limit = (n - 1) / 2;
            for(int i=0;i<=limit;i++)
            {
                for (int j= i; j < n - 1 - i; j++)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[n - 1 - j][i];
                    matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                    matrix[n - 1 - i][n-1-j] = matrix[j][n - 1 - i];
                    matrix[j][n - 1 - i] = temp;
                }
            }          
        }

    }
}
