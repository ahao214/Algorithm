using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 240. 搜索二维矩阵 II
    /// </summary>
    public class SearchMatrix
    {
        public bool Method(int[][] matrix, int target)
        {
            foreach (int[] row in matrix)
            {
                foreach (int element in row)
                {
                    if (element == target)
                    {
                        return true;
                    }
                }
            }
            return false;           
        }

        //二分查找
        public bool SearchMatrixs(int[][] matrix, int target)
        {
            foreach (int[] row in matrix)
            {
                int index = Search(row, target);
                if (index >= 0)
                {
                    return true;
                }
            }
            return false;
        }

        public int Search(int[] nums, int target)
        {
            int low = 0, high = nums.Length - 1;
            while (low <= high)
            {
                int mid = (high - low) / 2 + low;
                int num = nums[mid];
                if (num == target)
                {
                    return mid;
                }
                else if (num > target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return -1;
        }     
    }
}
