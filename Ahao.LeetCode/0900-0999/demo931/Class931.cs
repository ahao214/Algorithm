using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo931
{
    internal class Class931
    {
        public int MinFallingPathSum(int[][] matrix)
        {
            int n = matrix.Length;
            int[][] dp = new int[n][];
            for (int i = 0; i < n; i++)
            {
                dp[i] = new int[n];
            }
            for (int i = 0; i < n; i++)
            {
                dp[0][i] = matrix[0][i];
            }

            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int upValue = dp[i - 1][j];
                    if (j == 0)
                    {
                        int upRightValue = dp[i - 1][j + 1];
                        upValue = Math.Min(upValue, upRightValue);
                    }
                    else if (j == n - 1)
                    {
                        int upLeftValue = dp[i - 1][j - 1];
                        upValue = Math.Min(upValue, upLeftValue);
                    }
                    else
                    {
                        int upRightValue = dp[i - 1][j + 1];
                        int upLeftValue = dp[i - 1][j - 1];
                        upValue = Math.Min(upValue, Math.Min(upLeftValue, upRightValue));
                    }
                    dp[i][j] = upValue + matrix[i][j];
                }
            }
            return dp[n - 1].Min();
        }
    }
}
