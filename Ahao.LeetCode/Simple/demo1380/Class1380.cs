using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    /*
1380. 矩阵中的幸运数
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
*/
    public class Class1380
    {
        public IList<int> LuckyNumbers(int[][] matrix)
        {
            //int[][] matrix = new int[4][];
            //matrix[0] = new int[] { 3, 6 };
            //matrix[1] = new int[] { 7, 1 };
            //matrix[2] = new int[] { 5, 2 };
            //matrix[3] = new int[] { 4, 8 };
            IList<int> res = new List<int>();
            int m = matrix.Length;
            int n = matrix[0].Length;
            int col = 0;
            for (int i = 0; i < m; i++)
            {
                int minRow = int.MaxValue;
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] < minRow)
                    {
                        minRow = matrix[i][j];
                        col = j;
                    }
                }
                if (isMaxCol(matrix, col, minRow))
                    res.Add(minRow);
            }
            return res;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="matrix"></param>
        /// <param name="col">列号</param>
        /// <param name="minRow">每一行的最小值</param>
        /// <returns></returns>
        public bool isMaxCol(int[][] matrix, int col, int minRow)
        {
            bool res = true;
            for (int k = 0; k < matrix.Length; k++)
            {
                if (matrix[k][col] > minRow)
                    return false;
            }
            return res;
        }
    }
}
