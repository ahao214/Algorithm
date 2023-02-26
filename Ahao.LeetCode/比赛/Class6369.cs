using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6369. 左右元素和的差值  

给你一个下标从 0 开始的整数数组 nums ，请你找出一个下标从 0 开始的整数数组 answer ，其中：

answer.length == nums.length
answer[i] = |leftSum[i] - rightSum[i]|
其中：

leftSum[i] 是数组 nums 中下标 i 左侧元素之和。如果不存在对应的元素，leftSum[i] = 0 。
rightSum[i] 是数组 nums 中下标 i 右侧元素之和。如果不存在对应的元素，rightSum[i] = 0 。
返回数组 answer 。
     */
    public class Class6369
    {
        public int[] LeftRigthDifference(int[] nums)
        {
            int n = nums.Length;
            int[] res = new int[n];
            int[] leftSum = new int[n];
            int[] rightSum = new int[n];

            leftSum[0] = 0;
            rightSum[n - 1] = 0;
            for (int i = 0; i < n - 1; i++)
            {
                leftSum[i + 1] = nums[i] + leftSum[i];
            }
            for (int i = n - 1; i > 0; i--)
            {
                rightSum[i - 1] = nums[i] + rightSum[i];
            }

            for (int i = 0; i < n; i++)
                res[i] = Math.Abs(leftSum[i] - rightSum[i]);

            return res;
        }

    }
}
