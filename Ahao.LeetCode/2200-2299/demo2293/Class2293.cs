using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2200_2299.demo2293
{
    public class Class2293
    {
        /// <summary>
        /// 递归
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MinMaxGame(int[] nums)
        {
            int n = nums.Length;
            if (n == 1)
            {
                return nums[0];
            }
            int[] newNums = new int[n / 2];
            for (int i = 0; i < newNums.Length; i++)
            {
                if (i % 2 == 0)
                {
                    newNums[i] = Math.Min(nums[2 * i], nums[2 * i + 1]);
                }
                else
                {
                    newNums[i] = Math.Max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            return MinMaxGame(newNums);
        }



        /// <summary>
        /// 模拟
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MinMaxGame2(int[] nums)
        {
            int n = nums.Length;
            while (n != 1)
            {
                int[] newNums = new int[n / 2];
                for (int i = 0; i < newNums.Length; i++)
                {
                    if (i % 2 == 0)
                    {
                        newNums[i] = Math.Min(nums[2 * i], nums[2 * i + 1]);
                    }
                    else
                    {
                        newNums[i] = Math.Max(nums[2 * i], nums[2 * i + 1]);
                    }
                }
                nums = newNums;
                n /= 2;
            }
            return nums[0];
        }

    }
}
