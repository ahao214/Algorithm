using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo795
{
    public class Class795
    {
        /// <summary>
        /// 一次遍历
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="left"></param>
        /// <param name="right"></param>
        /// <returns></returns>
        public int NumSubarrayBoundedMax(int[] nums, int left, int right)
        {
            int res = 0, last2 = -1, last1 = -1;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] >= left && nums[i] <= right)
                {
                    last1 = i;
                }
                else if (nums[i] > right)
                {
                    last2 = i;
                    last1 = -1;
                }
                if (last1 != -1)
                {
                    res += last1 - last2;
                }
            }
            return res;
        }


        /// <summary>
        /// 计数
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="left"></param>
        /// <param name="right"></param>
        /// <returns></returns>
        public int NumSubarrayBoundedMax2(int[] nums, int left, int right)
        {
            return Count(nums, right) - Count(nums, left - 1);
        }

        public int Count(int[] nums, int lower)
        {
            int res = 0, cur = 0;
            foreach (int x in nums)
            {
                cur = x <= lower ? cur + 1 : 0;
                res += cur;
            }
            return res;
        }

    }
}
