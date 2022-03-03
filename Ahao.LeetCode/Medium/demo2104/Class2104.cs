using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    /*
     2104. 子数组范围和
给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。

返回 nums 中 所有 子数组范围的 和 。

子数组是数组中一个连续 非空 的元素序列。
     */
    public class Class2104
    {
        public long SubArrayRanges(int[] nums)
        {
            long res = 0;
            if (nums.Length == 1)
                return 0;
            int slow = 0, fast = 0;
            int tmpMax = int.MinValue;
            int tmpMin = int.MaxValue;
            int maxValue = nums[0], minValue = nums[0];
            while (slow < nums.Length)
            {
                while (fast < nums.Length)
                {
                    maxValue = Math.Max(nums[slow], nums[fast]);
                    minValue = Math.Min(nums[slow], nums[fast]);
                    tmpMax = Math.Max(tmpMax, maxValue);
                    tmpMin = Math.Min(tmpMin, minValue);
                    res += tmpMax - tmpMin;
                    fast++;
                }
                slow++;
                fast = slow;
                tmpMax = int.MinValue;
                tmpMin = int.MaxValue;
            }
            return res;
        }


        public long SubArrayRanges1(int[] nums)
        {
            int n = nums.Length;
            long ret = 0;
            for (int i = 0; i < n; i++)
            {
                int minVal = int.MaxValue, maxVal = int.MinValue;
                for (int j = i; j < n; j++)
                {
                    minVal = Math.Min(minVal, nums[j]);
                    maxVal = Math.Max(maxVal, nums[j]);
                    ret += maxVal - minVal;
                }
            }
            return ret;
        }

    }
}
