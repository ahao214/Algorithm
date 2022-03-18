using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo33
{
    /*
     33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
     */
    public class Class33
    {
        public int Search(int[] nums, int target)
        {
            if (nums == null || nums.Length == 0)
                return -1;

            var hi = nums.Length - 1;
            var low = 0;

            while (low <= hi)
            {
                var mid = low + (hi - low) / 2;
                var midVal = nums[mid];
                if (midVal == target)
                    return mid;

                if (nums[low] <= midVal)
                {
                    if (nums[low] <= target && target <= midVal)
                        hi = mid - 1;
                    else
                        low = mid + 1;
                }
                else
                {
                    if (midVal <= target && target <= nums[hi])                  low = mid + 1;                    
                    else                    
                        hi = mid - 1;                    
                }
            }
            return -1;
        }

        public int Search1(int[] nums, int target)
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
