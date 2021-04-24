using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 377. 组合总和 Ⅳ
    /// </summary>
    public class CombinationSumFour
    {
        #region 递归

        public int Method(int[] nums, int target)
        {
            Array.Sort(nums);
            int[] dp = new int[target + 1];
            for (int i = 0; i < dp.Length; i++)
            {
                dp[i] = -1;
            }
            int count = CountNum(nums, target, 0, dp);
            return count;
        }

        public int CountNum(int[] nums, int target, int start, int[] dp)
        {
            if (target == 0)
            {
                return 1;
            }
            if (dp[target] >= 0)
            {
                return dp[target];
            }
            int count = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (target >= nums[i])
                {
                    count += CountNum(nums, target - nums[i], i, dp);
                }
            }
            dp[target] = count;
            return count;
        }

        #endregion

        public int MethodT(int[] nums, int target)
        {
            Array.Sort(nums);
            int[] dp = new int[target + 1];
            dp[0] = 1;
            for (int i = 1; i <= target; i++)
            {
                for (int c = 0; c < nums.Length; c++)
                {
                    if (i - nums[c] >= 0)
                    {
                        dp[i] += dp[i - nums[c]];
                    }
                }
            }
            return dp[target];
        }

    }
}
