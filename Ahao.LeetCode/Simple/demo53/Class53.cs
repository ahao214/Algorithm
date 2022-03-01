using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo53
{
    /*
     53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
     */
    public class Class53
    {
        public int MaxSubArray(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                throw new ArgumentException();
            var max = nums[0];
            var pre = nums[0];
            for (int i = 1; i < nums.Length; i++)
            {
                pre = Math.Max(pre + nums[i], nums[i]);
                max = Math.Max(max, pre);
            }
            return max;
        }
    }
}
