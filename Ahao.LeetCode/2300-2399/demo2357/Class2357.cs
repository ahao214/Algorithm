using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2357
{
    public class Class2357
    {
        public int MinimumOperations(int[] nums)
        {
            int res = 0;
            Array.Sort(nums);
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > 0)
                {
                    SetZero(nums, i, nums[i]);
                    res++;
                }
            }
            return res;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="startIndex">开始遍历的索引</param>
        /// <param name="x">所要减去的数字</param>
        public void SetZero(int[] nums, int startIndex, int x)
        {
            for (int i = startIndex; i < nums.Length; i++)
            {
                nums[i] -= x;
            }
        }

    }
}
