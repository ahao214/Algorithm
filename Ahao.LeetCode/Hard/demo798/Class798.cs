using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard
{
    /*
     798. 得分最高的最小轮调
给定一个数组 A，我们可以将它按一个非负整数 K 进行轮调，这样可以使数组变为 A[K], A[K+1], A{K+2], ... A[A.length - 1], A[0], A[1], ..., A[K-1] 的形式。此后，任何值小于或等于其索引的项都可以记作一分。

例如，如果数组为 [2, 4, 1, 3, 0]，我们按 K = 2 进行轮调后，它将变成 [1, 3, 0, 2, 4]。这将记作 3 分，因为 1 > 0 [no points], 3 > 1 [no points], 0 <= 2 [one point], 2 <= 3 [one point], 4 <= 4 [one point]。

在所有可能的轮调中，返回我们所能得到的最高分数对应的轮调索引 K。如果有多个答案，返回满足条件的最小的索引 K。
     */
    public class Class798
    {
        public int BestRotation(int[] nums)
        {
            int i;
            int size = nums.Length;
            int sum = 0, maxScore = 0, maxScoreRotation = 0;
            int[] diff = new int[size + 1];
            for (i = 0; i < size; ++i)
            {
                int num = nums[i];
                if (i < num)  // 对于数字num来说，index为[num,size-1]时，可以获得积分。当前index<num，需要把它移到[num,size-1]区间
                {
                    diff[i + 1] += 1;  // 移动到size-1位置需要i+1次移动
                    diff[size - num + i + 1] -= 1; // 移动到num位置需要size - num + i次移动，再继续移动将不能获得积分
                }
                else
                {
                    diff[0] += 1;   // 移动[0,i-num]次可以获得积分
                    diff[i - num + 1] -= 1;
                    diff[i + 1] += 1;    // 移动到i后面都可以获得积分
                }
            }
            for (i = 0; i < size; i++)
            {
                sum += diff[i];
                if (sum > maxScore)
                {
                    maxScore = sum;
                    maxScoreRotation = i;
                }
            }
            return maxScoreRotation;

        }

        //超出时间限制
        public int BestRotation1(int[] nums)
        {
            int maxSum = 0;
            int result = 0;
            int len = nums.Length;
            int[] newNums = new int[len * 2];
            Array.Copy(nums, newNums, len);
            for (int i = 0; i < len; i++)
            {
                newNums[i + len] = nums[i];
            }

            for (int k = 0; k < len; k++)
            {
                //记录每次k的最大值
                int num = 0;
                for (int i = 0; i < len; i++)
                {
                    if (newNums[i + k] <= i)
                        num++;
                }
                if (num > maxSum)
                {
                    result = k;
                    maxSum = num;
                }
            }
            return result;
        }



    }
}
