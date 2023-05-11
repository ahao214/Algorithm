﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1330
{
    public class Class1330
    {
        public int MaxValueAfterReverse(int[] nums)
        {
            int value = 0, n = nums.Length;
            for (int i = 0; i < n - 1; i++)
            {
                value += Math.Abs(nums[i] - nums[i + 1]);
            }
            int mx1 = 0;
            for (int i = 1; i < n - 1; i++)
            {
                mx1 = Math.Max(mx1, Math.Abs(nums[0] - nums[i + 1]) - Math.Abs(nums[i] - nums[i + 1]));
                mx1 = Math.Max(mx1, Math.Abs(nums[n - 1] - nums[i - 1]) - Math.Abs(nums[i] - nums[i - 1]));
            }
            int mx2 = int.MinValue, mn2 = int.MaxValue;
            for (int i = 0; i < n - 1; i++)
            {
                int x = nums[i], y = nums[i + 1];
                mx2 = Math.Max(mx2, Math.Min(x, y));
                mn2 = Math.Min(mn2, Math.Max(x, y));
            }
            return value + Math.Max(mx1, 2 * (mx2 - mn2));
        }

    }
}
