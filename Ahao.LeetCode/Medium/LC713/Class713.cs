using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.LC713
{
    /// <summary>
    /// 713. 乘积小于K的子数组
    /// </summary>
    public class Class713
    {
        public int NumSubarrayProductLessThanK(int[] nums, int k)
        {
            if (nums == null || nums.Length == 0 || k == 0)
            {
                return 0;
            }

            int res = 0, left = 0, right = 0, prod = 1;

            while (left < nums.Length)
            {
                if (right < nums.Length && prod * nums[right] < k)
                {
                    prod = prod * nums[right];
                    right++;
                }
                else if (left == right)
                {
                    left++;
                    right++;
                }
                else
                {
                    res += right - left;
                    prod = prod / nums[left];
                    left++;
                }
            }
            return res;
        }
    }
}
