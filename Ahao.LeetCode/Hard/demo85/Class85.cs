using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Ahao.LeetCode.Hard.demo85
{
    /*
     85. 最大矩形
   给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
     */
    public class Class85
    {
        public int MaximalRectangle(char[][] matrix)
        {
            int m = matrix.Length;
            if (m == 0) return 0;
            int n = matrix[0].Length;
            int[,] cube = new int[m, n];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == '1')
                    {
                        cube[i, j] = j == 0 ? 1 : cube[i, j - 1] + 1;
                    }
                }
            }
            int res = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int w = cube[i, j];
                    for (int k = i; k >= 0; k--)
                    {
                        if (cube[k, j] == 0) break;
                        w = w < cube[k, j] ? w : cube[k, j];
                        res = Math.Max(res, (i - k + 1) * w);
                    }
                }
            }
            return res;
        }
    }
}
