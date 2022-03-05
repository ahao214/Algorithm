using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo81
{
    /*
     81. 搜索旋转排序数组 II
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。

给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。

你必须尽可能减少整个操作步骤。
     */
    public class Class81
    {
        public bool Search(int[] nums, int target)
        {
            if (nums == null || nums.Length == 0)
                return false;
            return Search(nums, 0, nums.Length - 1, target);
        }

        private bool Search(int[] nums, int low, int high, int target)
        {
            while (low < high)
            {
                var mid = low + (high - low) / 2;
                if (nums[mid] == target)
                    return true;
                if (low < mid - 1 && nums[low] < nums[mid - 1])
                {
                    if (nums[low] <= target && target <= nums[mid - 1])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                else if (mid + 1 < high && nums[mid] < nums[high])
                {
                    if (nums[mid] <= target && target <= nums[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                else
                {
                    return Search(nums, low, mid - 1, target) || Search(nums, mid + 1, high, target);
                }
            }
            return false;
        }
    }
}
