using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.LC74
{
    /// <summary>
    /// 74. 搜索二维矩阵
    /// </summary>
    public class Class74
    {
        public bool SearchMatrix(int[][] matrix, int target)
        {
            int rows = matrix.Length - 1;
            int cols = 0;
            while (rows >= 0 && cols < matrix[0].Length)
            {
                int num = matrix[rows][cols];
                if (num == target)
                {
                    return true;
                }
                else if (num > target)
                {
                    rows--;
                }
                else
                {
                    cols++;
                }
            }
            return false;
        }
    }
}
