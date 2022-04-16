using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6000_6099
{
    /*
     6060. 找到最接近 0 的数字 显示英文描述 
给你一个长度为 n 的整数数组 nums ，请你返回 nums 中最 接近 0 的数字。如果有多个答案，请你返回它们中的 最大值 。

 

示例 1：

输入：nums = [-4,-2,1,4,8]
输出：1
解释：
-4 到 0 的距离为 |-4| = 4 。
-2 到 0 的距离为 |-2| = 2 。
1 到 0 的距离为 |1| = 1 。
4 到 0 的距离为 |4| = 4 。
8 到 0 的距离为 |8| = 8 。
所以，数组中距离 0 最近的数字为 1 。
示例 2：

输入：nums = [2,-1,1]
输出：1
解释：1 和 -1 都是距离 0 最近的数字，所以返回较大值 1 。
 

提示：

1 <= n <= 1000
-105 <= nums[i] <= 105
     */
    public class Class6060
    {
        public int FindClosestNumber(int[] nums)
        {
            if (nums.Length == 1)
                return nums[0];
            Array.Sort(nums);
            int res = int.MaxValue;
            if (nums[nums.Length - 1] <= 0)
                return nums[nums.Length - 1];
            if (nums[0] >= 0)
                return nums[0];
            foreach (var item in nums)
            {
                if (item == 0)
                    return item;
            }
            int lastfushu = 0;
            int firstzhengshu = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] >= 0)
                {
                    lastfushu = nums[i - 1];
                    break;
                }
            }
            for (int i = nums.Length - 1; i >= 0; i--)
            {
                if (nums[i] <= 0)
                {
                    firstzhengshu = nums[i + 1];
                    break;
                }
            }
            if (Math.Abs(lastfushu) == Math.Abs(firstzhengshu))
                res = firstzhengshu;
            else
            {
                if (Math.Abs(lastfushu) > Math.Abs(firstzhengshu))
                    res = firstzhengshu;
                else
                    res = lastfushu;
            }
            return res;

        }
    }
}
