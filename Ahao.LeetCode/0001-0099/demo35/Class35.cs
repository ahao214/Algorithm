using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo35
{
    /*
     35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
     */
    public class Class35
    {
        public int SearchInsert(int[] nums, int target)
        {
            if (nums == null || nums.Length == 0)
                return -1;
            var low = 0;
            var high = nums.Length - 1;
            while (low <= high)
            {
                var mid = low + (high - low) / 2;
                if (nums[mid] == target)
                    return mid;
                if (target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return low;
        }
    }
}
