﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1775
{
    public class Class1775
    {
        public int MinOperations(int[] nums1, int[] nums2)
        {
            int n = nums1.Length, m = nums2.Length;
            if (6 * n < m || 6 * m < n)
            {
                return -1;
            }
            int[] cnt1 = new int[7];
            int[] cnt2 = new int[7];
            int diff = 0;
            foreach (int i in nums1)
            {
                ++cnt1[i];
                diff += i;
            }
            foreach (int i in nums2)
            {
                ++cnt2[i];
                diff -= i;
            }
            if (diff == 0)
            {
                return 0;
            }
            if (diff > 0)
            {
                return Help(cnt2, cnt1, diff);
            }
            return Help(cnt1, cnt2, -diff);
        }

        public int Help(int[] h1, int[] h2, int diff)
        {
            int[] h = new int[7];
            for (int i = 1; i < 7; ++i)
            {
                h[6 - i] += h1[i];
                h[i - 1] += h2[i];
            }
            int res = 0;
            for (int i = 5; i > 0 && diff > 0; --i)
            {
                int t = Math.Min((diff + i - 1) / i, h[i]);
                res += t;
                diff -= t * i;
            }
            return res;
        }
    }
}
