using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo688
{
    public class Class688
    {
        public double KnightProbability(int n, int k, int row, int column)
        {
            int[][] dirs = { new int[] { -2, 1 }, new int[] { -2, -1 }, new int[] { 2, 1 }, new int[] { 2, -1 }, new int[] { 1, 2 }, new int[] { 1, -2 }, new int[] { -1, -2 }, new int[] { -1, 2 } };

            double[,,] dp = new double[k + 1, n, n];
            for (int step = 0; step <= k; step++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        //走完K步
                        if (step == 0)
                        {
                            dp[step, i, j] = 1;
                        }
                        else
                        {
                            foreach (var dir in dirs)
                            {
                                int dx = i + dir[0], dy = j + dir[1];
                                if (dx >= 0 && dx < n && dy >= 0 && dy < n)
                                    dp[step, i, j] += dp[step - 1, dx, dy] / 8;
                            }
                        }
                    }
                }
            }
            return dp[k, row, column];
        }
    }
}
