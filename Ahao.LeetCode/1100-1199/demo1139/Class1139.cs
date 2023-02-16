using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1139
{
    public class Class1139
    {
        public int Largest1BorderedSquare(int[][] grid)
        {
            int m = grid.Length, n = grid[0].Length;
            int[][] left = new int[m + 1][];
            int[][] up = new int[m + 1][];
            for (int i = 0; i <= m; i++)
            {
                left[i] = new int[n + 1];
                up[i] = new int[n + 1];
            }
            int maxBorder = 0;
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (grid[i - 1][j - 1] == 1)
                    {
                        left[i][j] = left[i][j - 1] + 1;
                        up[i][j] = up[i - 1][j] + 1;
                        int border = Math.Min(left[i][j], up[i][j]);
                        while (left[i - border + 1][j] < border || up[i][j - border + 1] < border)
                        {
                            border--;
                        }
                        maxBorder = Math.Max(maxBorder, border);
                    }
                }
            }
            return maxBorder * maxBorder;
        }


    }
}
