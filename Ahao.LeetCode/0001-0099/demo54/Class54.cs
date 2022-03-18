using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo54
{
    /*
     54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
     */
    public class Class54
    {
        public IList<int> SpiralOrder(int[][] matrix)
        {
            if (matrix == null || matrix.Length == 0)
                return new List<int>(0);
            if (matrix.Any(t => t == null || t.Length != matrix[0].Length))
                throw new ArgumentException();
            var row = 0;
            var col = 0;
            var rowstep = 0;
            var colstep = 1;
            var rowUpBoard = matrix.Length;
            var rowLoBoard = 0;
            var colUpBoard = matrix[0].Length;
            var colLoBoard = -1;
            var lst = new List<int>(matrix.Length * matrix[0].Length);
            while (lst.Count < matrix.Length * matrix[0].Length)
            {
                lst.Add(matrix[row][col]);
                if (rowstep != 0)
                {
                    var nextRow = row + rowstep;
                    if (nextRow == rowUpBoard)
                        rowUpBoard--;
                    else if (nextRow == rowLoBoard)
                        rowLoBoard++;
                    else
                    {
                        row = nextRow;
                        continue;
                    }
                    colstep = -rowstep;
                    rowstep = 0;
                    col += colstep;
                }
                else
                {
                    var nextCol = col + colstep;
                    if (nextCol == colUpBoard)
                        colUpBoard--;
                    else if (nextCol == colLoBoard)
                        colLoBoard++;
                    else
                    {
                        col = nextCol;
                        continue;
                    }
                    rowstep = colstep;
                    colstep = 0;
                    row += rowstep;
                }
            }
            return lst;
        }
    }
}
