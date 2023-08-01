using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2681
{
    internal class Class2681
    {

        public int SumOfPower(int[] nums)
        {
            Array.Sort(nums);
            int[] dp = new int[nums.Length];
            int[] preSum = new int[nums.Length + 1];
            int res = 0, mod = 1000000007;
            for (int i = 0; i < nums.Length; i++)
            {
                dp[i] = (nums[i] + preSum[i]) % mod;
                preSum[i + 1] = (preSum[i] + dp[i]) % mod;
                res = (int)((res + (long)nums[i] * nums[i] % mod * dp[i]) % mod);
                if (res < 0)
                {
                    res += mod;
                }
            }
            return res;
        }

    }
}
