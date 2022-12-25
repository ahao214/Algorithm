﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1739
{
    public class Class1739
    {
        /// <summary>
        /// 二分查找
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public int MinimumBoxes(int n)
        {
            int i = 0, j = 0;
            int low = 1, high = Math.Min(n, 100000);
            while (low < high)
            {
                int mid = (low + high) >> 1;
                long sum = (long)mid * (mid + 1) * (mid + 2) / 6;
                if (sum >= n)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            i = low;
            n = (int)(n - (long)(i - 1) * i * (i + 1) / 6);
            low = 1;
            high = i;
            while (low < high)
            {
                int mid = (low + high) >> 1;
                long sum = (long)mid * (mid + 1) / 2;
                if (sum >= n)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            j = low;
            return (i - 1) * i / 2 + j;
        }
    }
}
