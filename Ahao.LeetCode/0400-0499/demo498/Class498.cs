﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo498
{
    public class Class498
    {
        public int[] FindDiagonalOrder(int[][] mat)
        {
            int m = mat.Length;
            int n = mat[0].Length;
            int[] res = new int[m * n];
            int pos = 0;
            for (int i = 0; i < m + n - 1; i++)
            {
                if (i % 2 == 1)
                {
                    int x = i < n ? 0 : i - n + 1;
                    int y = i < n ? i : n - 1;
                    while (x < m && y >= 0)
                    {
                        res[pos] = mat[x][y];
                        pos++;
                        x++;
                        y--;
                    }
                }
                else
                {
                    int x = i < m ? i : m - 1;
                    int y = i < m ? 0 : i - m + 1;
                    while (x >= 0 && y < n)
                    {
                        res[pos] = mat[x][y];
                        pos++;
                        x--;
                        y++;
                    }
                }
            }
            return res;
        }

    }
}
