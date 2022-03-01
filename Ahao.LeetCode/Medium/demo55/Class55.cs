using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo55
{
    /*
     55. 跳跃游戏
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
     */
    public class Class55
    {
        public bool CanJump(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                return false;
            var nextPos = 0 + nums[0];
            var i = 0;
            while (i <= nextPos)
            {
                nextPos = Math.Max(nextPos, i + nums[i]);
                if (nextPos >= nums.Length - 1)
                    return true;
                i++;
            }
            return false;
        }
    }
}
