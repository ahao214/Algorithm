﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    public class Class1726
    {
        public int TupleSameProduct(int[] nums)
        {
            int n = nums.Length;
            IDictionary<int, int> cnt = new Dictionary<int, int>();
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int key = nums[i] * nums[j];
                    cnt.TryAdd(key, 0);
                    cnt[key]++;
                }
            }
            int ans = 0;
            foreach (KeyValuePair<int, int> pair in cnt)
            {
                int v = pair.Value;
                ans += v * (v - 1) * 4;
            }
            return ans;
        }


    }
}
