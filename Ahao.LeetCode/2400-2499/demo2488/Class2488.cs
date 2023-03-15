﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2488
{
    public class Class2488
    {

        public int CountSubarrays(int[] nums, int k)
        {
            int n = nums.Length;
            int kIndex = -1;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == k)
                {
                    kIndex = i;
                    break;
                }
            }
            int ans = 0;
            IDictionary<int, int> counts = new Dictionary<int, int>();
            counts.Add(0, 1);
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += sign(nums[i] - k);
                if (i < kIndex)
                {
                    if (!counts.ContainsKey(sum))
                    {
                        counts.Add(sum, 1);
                    }
                    else
                    {
                        counts[sum]++;
                    }
                }
                else
                {
                    int prev0 = counts.ContainsKey(sum) ? counts[sum] : 0;
                    int prev1 = counts.ContainsKey(sum - 1) ? counts[sum - 1] : 0;
                    ans += prev0 + prev1;
                }
            }
            return ans;
        }

        public int sign(int num)
        {
            if (num == 0)
            {
                return 0;
            }
            return num > 0 ? 1 : -1;
        }
    }
}
