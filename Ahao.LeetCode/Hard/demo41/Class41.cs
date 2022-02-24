using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo41
{
    /*
     41. 缺失的第一个正数
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
     */
    public class Class41
    {
        public int FirstMissingPositive(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                return 1;
            for (int i = 0; i < nums.Length; i++)
            {
                var ni = nums[i];
                if (ni <= 0 || ni > nums.Length)
                    continue;
                while (nums[ni - 1] != ni)
                {
                    var tmp = nums[ni - 1];
                    nums[ni - 1] = ni;
                    ni = tmp;
                    if (ni <= 0 || ni > nums.Length)
                        break;
                }
            }

            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] != i + 1)
                    return i + 1;
            }
            return nums.Length + 1;
        }
    }
}
