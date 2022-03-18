using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo73
{
    /*
     73. 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
     */
    public class Class73
    {
        public void SetZeroes(int[][] matrix)
        {
            var rows = new bool[matrix.Length];
            var cols = new bool[matrix[0].Length];
            for (int row = 0; row < matrix.Length; row++)
            {
                for (int col = 0; col < matrix[row].Length; col++)
                {
                    if (matrix[row][col] == 0)
                    {
                        rows[row] = true;
                        cols[col] = true;
                    }
                }
            }

            for (int row = 0; row < rows.Length; row++)
            {
                if (rows[row])
                {
                    for (int col = 0; col < matrix[row].Length; col++)
                    {
                        matrix[row][col] = 0;
                    }
                }
            }

            for (int col = 0; col < cols.Length; col++)
            {
                if (cols[col])
                {
                    for (int row = 0; row < matrix.Length; row++)
                    {
                        matrix[row][col] = 0;
                    }
                }
            }
        }
    }
}
