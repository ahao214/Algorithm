using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2373
{
    public class Class2373
    {
        public int[][] LargestLocal(int[][] grid)
        {
            int n = grid.Length;
            int[][] res = new int[n - 2][];
            for (int i = 0; i < n - 2; i++)
            {
                res[i] = new int[n - 2];
                for (int j = 0; j < n - 2; j++)
                {
                    res[i][j] = GetMaxValue(grid, i, j);
                }
            }
            return res;
        }

        public int GetMaxValue(int[][] grid, int startX, int startY)
        {
            int maxValue = int.MinValue;
            for (int i = startX; i < startX + 3; i++)
            {
                for (int j = startY; j < startY + 3; j++)
                {
                    maxValue = Math.Max(maxValue, grid[i][j]);
                }
            }
            return maxValue;
        }



        public int[][] LargestLocal2(int[][] grid)
        {
            int n = grid.Length;
            int[][] res = new int[n - 2][];
            for (int i = 0; i < n - 2; i++)
            {
                res[i] = new int[n - 2];
                for (int j = 0; j < n - 2; j++)
                {
                    for (int x = i; x < i + 3; x++)
                    {
                        for (int y = j; y < j + 3; y++)
                        {
                            res[i][j] = Math.Max(res[i][j], grid[x][y]);
                        }
                    }
                }
            }
            return res;
        }
    }
}
