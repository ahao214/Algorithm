using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6367. 求出最多标记下标  

给你一个下标从 0 开始的整数数组 nums 。

一开始，所有下标都没有被标记。你可以执行以下操作任意次：

选择两个 互不相同且未标记 的下标 i 和 j ，满足 2 * nums[i] <= nums[j] ，标记下标 i 和 j 。
请你执行上述操作任意次，返回 nums 中最多可以标记的下标数目。

 

示例 1：

输入：nums = [3,5,2,4]
输出：2
解释：第一次操作中，选择 i = 2 和 j = 1 ，操作可以执行的原因是 2 * nums[2] <= nums[1] ，标记下标 2 和 1 。
没有其他更多可执行的操作，所以答案为 2 。
     */
    public class Class6367
    {
        public int maxNumOfMarkedIndices(int[] nums)
        {
            Array.Sort(nums);
            int l = 0;
            int r = nums.Length / 2;
            while (l < r)
            {
                int m = (l + r + 1) / 2;
                if (check(nums, m))
                {
                    l = m;
                }
                else
                {
                    r = m - 1;
                }
            }
            return l * 2;
        }

        public bool check(int[] nums, int k)
        {
            if (k * 2 > nums.Length)
            {
                return false;
            }
            int l = 0;
            int r = nums.Length - k;
            for (int i = 0; i < k; i++, l++, r++)
            {
                if (nums[l] * 2 > nums[r])
                {
                    return false;
                }
            }
            return true;
        }

        public int maxNumOfMarkedIndices2(int[] nums)
        {
            Array.Sort(nums);
            int n = nums.Length;
            int j = 0;
            for (int i = (n + 1) / 2; i < n; i++)
            {
                if (nums[j] * 2 <= nums[i])
                    j++;
            }
            return j * 2;
        }

    }
}
