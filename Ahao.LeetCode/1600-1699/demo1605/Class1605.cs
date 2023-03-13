﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1605
{
    public class Class1605
    {

        public int[][] RestoreMatrix(int[] rowSum, int[] colSum)
        {
            int n = rowSum.Length, m = colSum.Length;
            int[][] matrix = new int[n][];
            for (int row = 0; row < n; ++row)
            {
                matrix[row] = new int[m];
            }
            int i = 0, j = 0;
            while (i < n && j < m)
            {
                int v = Math.Min(rowSum[i], colSum[j]);
                matrix[i][j] = v;
                rowSum[i] -= v;
                colSum[j] -= v;
                if (rowSum[i] == 0)
                {
                    ++i;
                }
                if (colSum[j] == 0)
                {
                    ++j;
                }
            }
            return matrix;
        }

    }
}
