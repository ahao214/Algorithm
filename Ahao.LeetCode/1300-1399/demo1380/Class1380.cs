using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
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




        public IList<int> LuckyNumbers1(int[][] matrix)
        {
            int m = matrix.Length, n = matrix[0].Length;
            IList<int> ret = new List<int>();
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    bool isMin = true, isMax = true;
                    for (int k = 0; k < n; k++)
                    {
                        if (matrix[i][k] < matrix[i][j])
                        {
                            isMin = false;
                            break;
                        }
                    }
                    if (!isMin)
                    {
                        continue;
                    }
                    for (int k = 0; k < m; k++)
                    {
                        if (matrix[k][j] > matrix[i][j])
                        {
                            isMax = false;
                            break;
                        }
                    }
                    if (isMax)
                    {
                        ret.Add(matrix[i][j]);
                    }
                }
            }
            return ret;
        }

        //预处理方法
        public IList<int> LuckyNumbers2(int[][] matrix)
        {
            int m = matrix.Length, n = matrix[0].Length;
            int[] minRow = new int[m];
            Array.Fill(minRow, int.MaxValue);
            int[] maxCol = new int[n];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    minRow[i] = Math.Min(minRow[i], matrix[i][j]);
                    maxCol[j] = Math.Max(maxCol[j], matrix[i][j]);
                }
            }
            IList<int> ret = new List<int>();
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j])
                    {
                        ret.Add(matrix[i][j]);
                    }
                }
            }
            return ret;
        }

    }
}
