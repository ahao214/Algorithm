﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1806
{
    public class Class1806
    {
        public int ReinitializePermutation(int n)
        {
            int[] perm = new int[n];
            int[] target = new int[n];
            for (int i = 0; i < n; i++)
            {
                perm[i] = i;
                target[i] = i;
            }
            int step = 0;
            while (true)
            {
                int[] arr = new int[n];
                for (int i = 0; i < n; i++)
                {
                    if ((i & 1) != 0)
                    {
                        arr[i] = perm[n / 2 + (i - 1) / 2];
                    }
                    else
                    {
                        arr[i] = perm[i / 2];
                    }
                }
                perm = arr;
                step++;
                if (Enumerable.SequenceEqual(perm, target))
                {
                    break;
                }
            }
            return step;
        }
    }
}
