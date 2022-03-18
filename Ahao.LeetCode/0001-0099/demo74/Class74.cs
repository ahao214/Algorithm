using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo74
{
    /*
     74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
     */
    public class Class74
    {
        public bool SearchMatrix(int[][] matrix, int target)
        {
            int rowIndex = binarySearchFirstColumn(matrix, target);
            if (rowIndex < 0)
            {
                return false;
            }
            return binarySearchRow(matrix[rowIndex], target);
        }

        public int binarySearchFirstColumn(int[][] matrix, int target)
        {
            int low = -1, high = matrix.Length - 1;
            while (low < high)
            {
                int mid = (high - low + 1) / 2 + low;
                if (matrix[mid][0] <= target)
                {
                    low = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
            return low;
        }

        public bool binarySearchRow(int[] row, int target)
        {
            int low = 0, high = row.Length - 1;
            while (low <= high)
            {
                int mid = (high - low) / 2 + low;
                if (row[mid] == target)
                {
                    return true;
                }
                else if (row[mid] > target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return false;
        }


        public bool SearchMatrix1(int[][] matrix, int target)
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


        public bool SearchMatrix2(int[][] matrix, int target)
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
