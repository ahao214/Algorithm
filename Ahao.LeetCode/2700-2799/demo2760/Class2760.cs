﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2760
{
    public class Class2760
    {
        public int LongestAlternatingSubarray(int[] nums, int threshold)
        {
            int res = 0, n = nums.Length;
            for (int l = 0; l < n; l++)
            {
                for (int r = l; r < n; r++)
                {
                    if (IsSatisfied(nums, l, r, threshold))
                    {
                        res = Math.Max(res, r - l + 1);
                    }
                }
            }
            return res;
        }

        public bool IsSatisfied(int[] nums, int l, int r, int threshold)
        {
            if (nums[l] % 2 != 0)
            {
                return false;
            }
            for (int i = l; i <= r; i++)
            {
                if (nums[i] > threshold || (i < r && nums[i] % 2 == nums[i + 1] % 2))
                {
                    return false;
                }
            }
            return true;
        }





    }
}
