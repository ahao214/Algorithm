using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2500
{
    internal class Class2500
    {
        public int DeleteGreatestValue(int[][] grid)
        {
            int res = 0;
            foreach (var item in grid)
            {
                Array.Sort(item);
            }
            int m = grid.Length;
            int n = grid[0].Length;
            for (int j = 0; j < n; j++)
            {
                int max = int.MinValue;
                for (int i = 0; i < m; i++)
                {
                    max = Math.Max(max, grid[i][j]);
                }
                res += max;
            }
            return res;
        }
    }
}
