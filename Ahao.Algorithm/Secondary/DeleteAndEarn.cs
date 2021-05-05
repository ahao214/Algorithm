using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 740. 删除并获得点数
    /// </summary>
    public class DeleteAndEarn
    {
        public int Method(int[] nums)
        {
            if (nums == null || nums.Length <= 0)
            {
                return 0;
            }
            else if (nums.Length == 1)
            {
                return nums[0];
            }

            int maxValue = 0;
            foreach (var item in nums)
            {
                maxValue = Math.Max(maxValue, item);
            }
            //创建一个新的数组
            int[] dp = new int[maxValue + 1];
            foreach (var item in nums)
            {
                dp[item] += item;
            }

            int first = dp[0];
            int second = Math.Max(dp[0], dp[1]);
            for (var i = 2; i < dp.Length; i++)
            {
                int temp = second;
                second = Math.Max(first + dp[i], second);
                first = temp;
            }
            return second;
        }
    }
}
