using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 673. 最长递增子序列的个数
    /// </summary>
    public class FindNumberOfLIS
    {
        public int Method(int[] nums)
        {
            int length = nums.Length, maxLength = 0, answer = 0;
            int[] dp = new int[length];
            int[] cnt = new int[length];
            for (int i = 0; i < length; i++)
            {
                dp[1] = 1;
                cnt[1] = 1;
                for (int j = 0; j < i; j++)
                {
                    if (nums[i] > nums[j])
                    {
                        if (dp[j] + 1 > dp[i])
                        {
                            dp[i] = dp[j] + 1;
                            cnt[i] = cnt[j]; // 重置计数
                        }
                        else if (dp[j] + 1 == dp[i])
                        {
                            cnt[i] += cnt[j];
                        }
                    }
                }
                if (dp[i] > maxLength)
                {
                    maxLength = dp[i];
                    answer = cnt[i]; // 重置计数
                }
                else if (dp[i] == maxLength)
                {
                    answer += cnt[i];
                }
            }
            return answer;
        }
    }
}
