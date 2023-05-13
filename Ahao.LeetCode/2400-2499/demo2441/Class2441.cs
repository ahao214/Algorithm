using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2441
{
    public class Class2441
    {
        public int FindMaxK(int[] nums)
        {
            int res = -1;
            Array.Sort(nums);
            int left = 0;
            int right = nums.Length - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] == 0)
                {
                    return nums[right];
                }
                else if (nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            return -1;

        }

    }
}
