using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo34
{
    /*
     34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。
     */
    public class Class34
    {
        public int[] SearchRange(int[] nums, int target)
        {
            if (nums == null || nums.Length == 0)
                return new int[] { -1, -1 };
            var low = 0;
            var high = nums.Length - 1;
            while (low <= high)
            {
                var mid = low + (high - low) / 2;
                if (nums[mid] == target)
                {
                    return new int[] { FindFirst(nums, low, mid, target), FindLast(nums, mid, high, target) };
                }
                if (target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            return new int[] { -1, -1 };
        }

        private int FindFirst(int[] arr, int low, int high, int target)
        {
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target)
                {
                    if (high == low)
                        return mid;
                    high = mid;
                }
                else if (target < arr[mid])
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

        private int FindLast(int[] arr, int low, int high, int target)
        {
            while (low <= high)
            {
                int mid = high - (high - low) / 2;
                if (arr[mid] == target)
                {
                    if (high == low)
                        return mid;
                    low = mid;
                }
                else if (target < arr[mid])
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
