using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo918
{
    internal class Class918
    {

        public int MaxSubarraySumCircular(int[] nums)
        {
            int n = nums.Length;
            int[] leftMax = new int[n];
            // 对坐标为 0 处的元素单独处理，避免考虑子数组为空的情况
            leftMax[0] = nums[0];
            int leftSum = nums[0];
            int pre = nums[0];
            int res = nums[0];
            for (int i = 1; i < n; i++)
            {
                pre = Math.Max(pre + nums[i], nums[i]);
                res = Math.Max(res, pre);
                leftSum += nums[i];
                leftMax[i] = Math.Max(leftMax[i - 1], leftSum);
            }

            // 从右到左枚举后缀，固定后缀，选择最大前缀
            int rightSum = 0;
            for (int i = n - 1; i > 0; i--)
            {
                rightSum += nums[i];
                res = Math.Max(res, rightSum + leftMax[i - 1]);
            }
            return res;
        }



        public int MaxSubarraySumCircular2(int[] nums)
        {
            int n = nums.Length;
            int preMax = nums[0], maxRes = nums[0];
            int preMin = nums[0], minRes = nums[0];
            int sum = nums[0];
            for (int i = 1; i < n; i++)
            {
                preMax = Math.Max(preMax + nums[i], nums[i]);
                maxRes = Math.Max(maxRes, preMax);
                preMin = Math.Min(preMin + nums[i], nums[i]);
                minRes = Math.Min(minRes, preMin);
                sum += nums[i];
            }
            if (maxRes < 0)
            {
                return maxRes;
            }
            else
            {
                return Math.Max(maxRes, sum - minRes);
            }
        }


    }
}
