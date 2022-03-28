﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    public class Class969
    {
        public IList<int> PancakeSort(int[] arr)
        {
            IList<int> ret = new List<int>();
            for (int n = arr.Length; n > 1; n--)
            {
                int index = 0;
                for (int i = 1; i < n; i++)
                {
                    if (arr[i] >= arr[index])
                    {
                        index = i;
                    }
                }
                if (index == n - 1)
                {
                    continue;
                }
                Reverse(arr, index);
                Reverse(arr, n - 1);
                ret.Add(index + 1);
                ret.Add(n);
            }
            return ret;
        }

        public void Reverse(int[] arr, int end)
        {
            for (int i = 0, j = end; i < j; i++, j--)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
