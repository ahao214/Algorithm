using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo213
{
    /// <summary>
    /// 213. 打家劫舍 II
    /// </summary>
    public class Class213
    {
        public int Rob(int[] nums)
        {
            int len = nums.Length;
            if (len == 1)
            {
                return nums[0];
            }
            if (len == 2)
            {
                return Math.Max(nums[0], nums[1]);
            }

            return Math.Max(RobRan(nums, 0, len - 2), RobRan(nums, 1, len - 1));
        }


        public int RobRan(int[] arr, int start, int end)
        {
            int first = arr[start];
            int second = Math.Max(arr[start], arr[start + 1]);

            for (int i = start + 2; i <= end; i++)
            {
                int tmp = second;
                second = Math.Max(first + arr[i], second);
                first = tmp;
            }
            return second;
        }
    }
}
