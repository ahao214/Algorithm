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


        public int Rob2(int[] nums)
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

            int pre2 = nums[0];
            int pre1 = Math.Max(nums[0], nums[1]);

            //0到N-2上的最好
            for (int i = 2; i < nums.Length - 1; i++)
            {
                int tmp = Math.Max(pre1, nums[i] + pre2);
                pre2 = pre1;
                pre1 = tmp;
            }
            int ans1 = pre1;
            pre2 = nums[1];
            pre1 = Math.Max(nums[1], nums[2]);


            //1到N-1上的最好
            for (int i = 3; i < len; i++)
            {
                int tmp = Math.Max(pre1, nums[i] + pre2);
                pre2 = pre1;
                pre1 = tmp;
            }
            int ans2 = pre1;
            return Math.Max(ans1, ans2);
        }
    }
}
