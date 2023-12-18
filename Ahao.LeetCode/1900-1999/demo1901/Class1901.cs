﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1900_1999.demo1901
{
    public class Class1901
    {
        public int[] FindPeakGrid(int[][] mat)
        {
            int m = mat.Length, n = mat[0].Length;
            int low = 0, high = m - 1;
            while (low <= high)
            {
                int i = (low + high) / 2;
                int j = -1, maxElement = -1;
                for (int k = 0; k < n; k++)
                {
                    if (mat[i][k] > maxElement)
                    {
                        j = k;
                        maxElement = mat[i][k];
                    }
                }
                if (i - 1 >= 0 && mat[i][j] < mat[i - 1][j])
                {
                    high = i - 1;
                    continue;
                }
                if (i + 1 < m && mat[i][j] < mat[i + 1][j])
                {
                    low = i + 1;
                    continue;
                }
                return new int[] { i, j };
            }
            return new int[0]; // impossible
        }

    }
}
