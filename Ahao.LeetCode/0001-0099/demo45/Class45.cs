using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo45
{
    /*
     45. 跳跃游戏 II
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。
     */
    public class Class45
    {
        public int Jump(int[] nums)
        {
            if (nums.Length == 1)
                return 0;
            var pn = nums[0];
            var step = 1;
            var i = 1;
            while (i < nums.Length - 1)
            {
                if (pn >= nums.Length - 1)
                    break;
                var pi = pn;
                while (i <= pi)
                {
                    pn = Math.Max(i + nums[i], pn);
                    i++;
                }
                step++;
                if (pn >= nums.Length - 1)
                    break;
            }
            return step;
        }


        public int Jump2(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                return 0;
            int step = 0;
            int cur = 0;
            int next = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (cur < i)
                {
                    step++;
                    cur = next;
                }
                next = Math.Max(next, i + nums[i]);
            }
            return step;
        }
    }
}
