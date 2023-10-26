﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1465
{
    internal class Class1465
    {

        public int MaxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts)
        {
            Array.Sort(horizontalCuts);
            Array.Sort(verticalCuts);
            return (int)((long)CalMax(horizontalCuts, h) * CalMax(verticalCuts, w) % 1000000007);
        }

        public int CalMax(int[] arr, int boardr)
        {
            int res = 0, pre = 0;
            foreach (int i in arr)
            {
                res = Math.Max(i - pre, res);
                pre = i;
            }
            return Math.Max(res, boardr - pre);
        }

    }
}
