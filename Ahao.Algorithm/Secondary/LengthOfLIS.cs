using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 300. 最长递增子序列
    /// </summary>
    public class LengthOfLIS
    {
        public int Method(int[] nums)
        {
            if (nums == null || nums.Length == 0)
            {
                return 0;
            }

            int res = 1;
            int[] dp = new int[nums.Length + 1];
            for (int i = 0; i < nums.Length; ++i)
                dp[i] = 1;
            for (int i = 1; i < nums.Length; ++i)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[j] < nums[i])
                    {
                        dp[i] = Math.Max(dp[i], dp[j] + 1);
                    }
                }
                res = Math.Max(res, dp[i]);
            }
            return res;
        }
    }
}
