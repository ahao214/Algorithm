using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo6000
{
    /*
     6000. 对奇偶下标分别排序 
给你一个下标从 0 开始的整数数组 nums 。根据下述规则重排 nums 中的值：

按 非递增 顺序排列 nums 奇数下标 上的所有值。
举个例子，如果排序前 nums = [4,1,2,3] ，对奇数下标的值排序后变为 [4,3,2,1] 。奇数下标 1 和 3 的值按照非递增顺序重排。
按 非递减 顺序排列 nums 偶数下标 上的所有值。
举个例子，如果排序前 nums = [4,1,2,3] ，对偶数下标的值排序后变为 [2,1,4,3] 。偶数下标 0 和 2 的值按照非递减顺序重排。
返回重排 nums 的值之后形成的数组。
     */
    public class Class6000
    {
        public int[] SortEvenOdd(int[] nums)
        {
            int len = nums.Length;
            if (len <= 2)
            {
                return nums;
            }
            int[] newNums = new int[len];

            List<int> odd = new List<int>();
            List<int> even = new List<int>();
            for (int i = 0; i < len; i++)
            {
                if (i % 2 == 0)
                {
                    //偶数递增
                    even.Add(nums[i]);
                }
                else
                {
                    //奇数递减
                    odd.Add(nums[i]);
                }
            }
            even.Sort();
            odd.Sort();
            odd.Reverse();
            for (int i = 0; i < even.Count; i++)
            {
                newNums[2 * i] = even[i];
            }
            for (int i = 0; i < odd.Count; i++)
            {
                newNums[2 * i + 1] = odd[i];
            }
            return newNums;
        }
    }
}
