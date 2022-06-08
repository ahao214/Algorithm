﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1037
{
    public class Class1037
    {
        public bool IsBoomerang(int[][] points)
        {
            int[] v1 = { points[1][0] - points[0][0], points[1][1] - points[0][1] };
            int[] v2 = { points[2][0] - points[0][0], points[2][1] - points[0][1] };
            return v1[0] * v2[1] - v1[1] * v2[0] != 0;
        }

    }
}
