﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo324
{
    public class Class324
    {
        public void WiggleSort(int[] nums)
        {
            int n = nums.Length;
            int[] arr = new int[n];
            Array.Copy(nums, arr, n);
            Array.Sort(arr);
            int x = (n + 1) / 2;
            for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--)
            {
                nums[i] = arr[j];
                if (i + 1 < n)
                {
                    nums[i + 1] = arr[k];
                }
            }
        }

    }
}
