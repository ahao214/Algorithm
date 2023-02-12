using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6355. 统计公平数对的数目  

给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和两个整数 lower 和 upper ，返回 公平数对的数目 。

如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：

0 <= i < j < n，且
lower <= nums[i] + nums[j] <= upper

    示例 1：

输入：nums = [0,1,7,4,4,5], lower = 3, upper = 6
输出：6
解释：共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) 。

     */
    public class Class6355
    {
        public long CountFairPairs(int[] nums, int lower, int upper)
        {
            Array.Sort(nums);
            long count = 0;
            for (int i = 0, j = nums.Length - 1, k = nums.Length - 1; i < nums.Length; i++)
            {
                for (; j >= 0 && nums[i] + nums[j] >= lower; j--)
                {
                }
                for (; k >= 0 && nums[i] + nums[k] > upper; k--)
                {
                }
                count += k - j - (i > j && i <= k ? 1 : 0);
            }
            return count / 2;
        }

        public long CountFairPairs2(int[] nums, int lower, int upper)
        {
            long res = 0;
            Array.Sort(nums);
            int left = 0;
            int right = 0;
            for (int i = nums.Length - 1; i >= 0; i--)
            {
                while (left < i && nums[left] + nums[i] < lower)
                    left++;
                while (right < i && nums[right] + nums[i] <= upper)
                    right++;
                if (i > left)
                    res += Math.Min(i, right) - 1;
            }
            return res;
        }

    }
}
