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



        public int SumOfPower2(int[] nums)
        {
            Array.Sort(nums);
            int dp = 0, preSum = 0;
            int res = 0, mod = 1000000007;
            for (int i = 0; i < nums.Length; i++)
            {
                dp = (nums[i] + preSum) % mod;
                preSum = (preSum + dp) % mod;
                res = (int)((res + (long)nums[i] * nums[i] % mod * dp) % mod);
                if (res < 0)
                {
                    res += mod;
                }
            }
            return res;
        }



        public int SumOfPower3(int[] nums)
        {
            int MOD = 1000000007;
            int length = nums.Length;
            Array.Sort(nums);
            long ans = 0;
            long sum = 0;
            for (int i = 0; i < length; i++)
            {
                ans = (ans + (sum + nums[i]) % MOD * nums[i] % MOD * nums[i] % MOD) % MOD;
                sum = (sum * 2 % MOD + nums[i]) % MOD;
            }
            return (int)ans;
        }


    }
}
