using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.LC153
{
    /// <summary>
    /// 153. 寻找旋转排序数组中的最小值
    /// </summary>
    public class Class153
    {
        public int FindMin(int[] nums)
        {
            int low = 0;
            int high = nums.Length - 1;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] < nums[high])
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return nums[low];
        }
    }
}
