using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo891
{
    public class Class891
    {
        public int SumSubseqWidths(int[] nums)
        {
            const int MOD = 1000000007;
            Array.Sort(nums);
            long res = 0;
            long x = nums[0], y = 2;
            for (int j = 1; j < nums.Length; j++)
            {
                res = (res + nums[j] * (y - 1) - x) % MOD;
                x = (x * 2 + nums[j]) % MOD;
                y = y * 2 % MOD;
            }
            return (int)((res + MOD) % MOD);
        }
    }
}
