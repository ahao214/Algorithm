using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LeetCode.Medium
{
    /// <summary>
    /// 33. 搜索旋转排序数组
    /// </summary>
    public class Class33
    {
        public int Search(int[] nums, int target)
        {
            if (nums.Length == 0)
            {
                return -1;
            }
            int low = 0;
            int high = nums.Length - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] > nums[low]) // 在数值大的一部分区间里
                {
                    if (nums[low] <= target && target < nums[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else if (nums[mid] < nums[high]) // 在数值小的一部分区间里
                {
                    if (nums[mid] < target && target <= nums[high])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
                else
                {
                    if (nums[low] == nums[mid])
                    {
                        low++;
                    }
                    if (nums[high] == nums[mid])
                    {
                        high--;
                    }
                }
            }
            return -1;
        }
    }
}
