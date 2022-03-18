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

        /// <summary>
        /// 单调栈
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public long SubArrayRanges2(int[] nums)
        {
            int n = nums.Length;
            int[] minLeft = new int[n];
            int[] minRight = new int[n];
            int[] maxLeft = new int[n];
            int[] maxRight = new int[n];
            Stack<int> minStack = new Stack<int>();
            Stack<int> maxStack = new Stack<int>();
            for (int i = 0; i < n; i++)
            {
                while (minStack.Count > 0 && nums[minStack.Peek()] > nums[i])
                {
                    minStack.Pop();
                }
                minLeft[i] = minStack.Count == 0 ? -1 : minStack.Peek();
                minStack.Push(i);

                // 如果 nums[maxStack.Peek()] == nums[i], 那么根据定义，
                // nums[maxStack.Peek()] 逻辑上小于 nums[i]，因为 maxStack.Peek() < i
                while (maxStack.Count > 0 && nums[maxStack.Peek()] <= nums[i])
                {
                    maxStack.Pop();
                }
                maxLeft[i] = maxStack.Count == 0 ? -1 : maxStack.Peek();
                maxStack.Push(i);
            }
            minStack.Clear();
            maxStack.Clear();
            for (int i = n - 1; i >= 0; i--)
            {
                // 如果 nums[minStack.Peek()] == nums[i], 那么根据定义，
                // nums[minStack.Peek()] 逻辑上大于 nums[i]，因为 minStack.Peek() > i
                while (minStack.Count > 0 && nums[minStack.Peek()] >= nums[i])
                {
                    minStack.Pop();
                }
                minRight[i] = minStack.Count == 0 ? n : minStack.Peek();
                minStack.Push(i);

                while (maxStack.Count > 0 && nums[maxStack.Peek()] < nums[i])
                {
                    maxStack.Pop();
                }
                maxRight[i] = maxStack.Count == 0 ? n : maxStack.Peek();
                maxStack.Push(i);
            }

            long sumMax = 0, sumMin = 0;
            for (int i = 0; i < n; i++)
            {
                sumMax += (long)(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
                sumMin += (long)(minRight[i] - i) * (i - minLeft[i]) * nums[i];
            }
            return sumMax - sumMin;
        }


    }
}
