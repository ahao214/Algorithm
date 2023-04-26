﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1031
{
    public class Class1031
    {
        public int MaxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen)
        {
            return Math.Max(Help(nums, firstLen, secondLen), Help(nums, secondLen, firstLen));
        }

        public int Help(int[] nums, int firstLen, int secondLen)
        {
            int suml = 0;
            for (int i = 0; i < firstLen; ++i)
            {
                suml += nums[i];
            }
            int maxSumL = suml;
            int sumr = 0;
            for (int i = firstLen; i < firstLen + secondLen; ++i)
            {
                sumr += nums[i];
            }
            int res = maxSumL + sumr;
            for (int i = firstLen + secondLen, j = firstLen; i < nums.Length; ++i, ++j)
            {
                suml += nums[j] - nums[j - firstLen];
                maxSumL = Math.Max(maxSumL, suml);
                sumr += nums[i] - nums[i - secondLen];
                res = Math.Max(res, maxSumL + sumr);
            }
            return res;
        }
    }
}
