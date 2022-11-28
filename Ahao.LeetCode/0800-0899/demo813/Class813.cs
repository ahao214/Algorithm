using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo813
{
    public class Class813
    {
        public double LargestSumOfAverages(int[] nums, int k)
        {
            int n = nums.Length;
            double[] prefix = new double[n + 1];
            for (int i = 0; i < n; i++)
            {
                prefix[i + 1] = prefix[i] + nums[i];
            }
            double[][] dp = new double[n + 1][];
            for (int i = 0; i <= n; i++)
            {
                dp[i] = new double[k + 1];
            }
            for (int i = 1; i <= n; i++)
            {
                dp[i][1] = prefix[i] / i;
            }
            for (int j = 2; j <= k; j++)
            {
                for (int i = j; i <= n; i++)
                {
                    for (int x = j - 1; x < i; x++)
                    {
                        dp[i][j] = Math.Max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
                    }
                }
            }
            return dp[n][k];
        }
    }
}
