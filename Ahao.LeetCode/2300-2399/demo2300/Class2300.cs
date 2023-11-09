﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2300
{
    public class Class2300
    {

        public int[] SuccessfulPairs(int[] spells, int[] potions, long success)
        {
            Array.Sort(potions);
            int n = spells.Length, m = potions.Length;
            int[] res = new int[n];
            for (int i = 0; i < n; i++)
            {
                long t = (success + spells[i] - 1) / spells[i] - 1;
                res[i] = m - BinarySearch(potions, 0, m - 1, t);
            }
            return res;
        }

        public int BinarySearch(int[] arr, int lo, int hi, long target)
        {
            int res = hi + 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid] > target)
                {
                    res = mid;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            return res;
        }

    }
}
