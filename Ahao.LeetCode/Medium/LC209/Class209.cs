using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.LC209
{
    /// <summary>
    /// 209. 长度最小的子数组
    /// </summary>
    public class Class209
    {
        public int MinSubArrayLen(int target, int[] nums)
        {
            int left = 0;
            int sum = 0;
            int res = nums.Length + 1;

            for (int i = 0; i < nums.Length; i++)
            {
                sum += nums[i];
                while (sum >= target)
                {
                    res = Math.Min(res, i - left + 1);
                    sum -= nums[left];
                    left++;
                }
            }

            if (res == nums.Length + 1)
            {
                return 0;
            }
            return res;
        }
    }
}
