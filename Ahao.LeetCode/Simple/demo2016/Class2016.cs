using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2016
{

    /*
    2016. 增量元素之间的最大差值
    给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。

    返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。
*/

    public class Class2016
    {
        public int MaximumDifference(int[] nums)
        {
            int prev = nums[0];
            int maxValue = -1;
            for (int i = 1; i < nums.Length; i++)
            {
                if (nums[i] > prev)
                {
                    maxValue = Math.Max(maxValue, nums[i] - prev);
                }
                else
                {
                    prev = nums[i];
                }
            }
            return maxValue;
        }
    }
}
