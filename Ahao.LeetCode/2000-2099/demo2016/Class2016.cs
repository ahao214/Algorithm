using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2016
{
    public class Class2016
    {
        public int MaximumDifference(int[] nums)
        {
            int prev = nums[0];
            int maxValue = -1;
            for (int i = 1; i < nums.Length; i++)
            {
                if (nums[i] > prev)
                {
                    maxValue = Math.Max(maxValue, nums[i] - prev);
                }
                else
                {
                    prev = nums[i];
                }
            }
            return maxValue;
        }
    }
}
