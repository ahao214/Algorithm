using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo5987
{
    /*
     5987. 删除元素后和的最小差值 
给你一个下标从 0 开始的整数数组 nums ，它包含 3 * n 个元素。

你可以从 nums 中删除 恰好 n 个元素，剩下的 2 * n 个元素将会被分成两个相同大小 的部分。

前面 n 个元素属于第一部分，它们的和记为 sumfirst 。
后面 n 个元素属于第二部分，它们的和记为 sumsecond 。
两部分和的 差值 记为 sumfirst - sumsecond 。

比方说，sumfirst = 3 且 sumsecond = 2 ，它们的差值为 1 。
再比方，sumfirst = 2 且 sumsecond = 3 ，它们的差值为 -1 。
请你返回删除 n 个元素之后，剩下两部分和的 差值的最小值 是多少。
     */
    public class Class5987
    {
        //有问题需要修改
        public long MinimumDifference(int[] nums)
        {
            int res = 0;
            //删除的元素的个数
            int deleteCount = nums.Length / 3;
            int frontMax = int.MinValue;
            int backMax = int.MaxValue;
            int sumFront = 0;
            int sumBack = 0;
            if (nums.Length % 2 == 0)
            {
                for (int i = 0; i < nums.Length / 2; i++)
                {
                    frontMax = Math.Max(nums[i], frontMax);
                    sumFront += nums[i];
                }
                for (int i = nums.Length / 2; i < nums.Length; i++)
                {
                    backMax = Math.Min(backMax, nums[i]);
                    sumBack += nums[i];
                }
                res = (sumFront - frontMax) - (sumBack - backMax);
            }
            else
            {
                for (int i = 0; i < nums.Length / 2 + 1; i++)
                {
                    frontMax = Math.Max(nums[i], frontMax);
                    sumFront += nums[i];
                }
                for (int i = nums.Length / 2; i < nums.Length; i++)
                {
                    backMax = Math.Min(backMax, nums[i]);
                    sumBack += nums[i];
                }
                res = (sumFront - frontMax) - (sumBack - backMax);
            }

            return res;
        }
    }
}
