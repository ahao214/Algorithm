using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{

    /*
     6361. 修改两个元素的最小分数  

给你一个下标从 0 开始的整数数组 nums 。

nums 的 最小 得分是满足 0 <= i < j < nums.length 的 |nums[i] - nums[j]| 的最小值。
nums的 最大 得分是满足 0 <= i < j < nums.length 的 |nums[i] - nums[j]| 的最大值。
nums 的分数是 最大 得分与 最小 得分的和。
我们的目标是最小化 nums 的分数。你 最多 可以修改 nums 中 2 个元素的值。

请你返回修改 nums 中 至多两个 元素的值后，可以得到的 最小分数 。

|x| 表示 x 的绝对值。

输入：nums = [1,4,3]
输出：0
解释：将 nums[1] 和 nums[2] 的值改为 1 ，nums 变为 [1,1,1] 。|nums[i] - nums[j]| 的值永远为 0 ，所以我们返回 0 + 0 = 0 。
 
     */
    public class Class6361
    {
        public int MinimizeSum(int[] nums)
        {
            int res = 0;
            int n = nums.Length;
            if (n == 3)
                return res;

            Array.Sort(nums);
            res = Math.Min(nums[n - 1] - nums[2], nums[n - 2] - nums[1]);
            int tmp = nums[n - 3] - nums[0];
            res = Math.Min(res, tmp);
            return res;
        }

    }
}
