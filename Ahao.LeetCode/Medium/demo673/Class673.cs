using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo673
{
    /// <summary>
    /// 673. 最长递增子序列的个数

    /// </summary>
    public class Class673
    {
        public int FindNumberOfLIS(int[] nums)
        {
            int n = nums.Length;
            int max = int.MinValue;
            int[] dp = new int[n];
            int[] count = new int[n];
            for (int i = 0; i < n; i++)
            {
                dp[i] = count[i] = 1;
                for (int j = 0; j < i; j++)
                {
                    if (nums[j] < nums[i])
                    {
                        if (dp[i] < dp[j] + 1)
                        {
                            dp[i] = dp[j] + 1;
                            count[i] = count[j];
                        }
                        else if (dp[i] == dp[j] + 1)
                        {
                            count[i] += count[j];
                        }
                    }
                }
                if (max < dp[i])
                {
                    max = dp[i];
                }
            }

            int result = 0;
            for (int i = 0; i < n; i++)
            {
                if (dp[i] == max)
                {
                    result += count[i];
                }
            }
            return result;
        }
    }
}
