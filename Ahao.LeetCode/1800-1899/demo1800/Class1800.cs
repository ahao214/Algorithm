using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1800
{
    public class Class1800
    {
        public int MaxAscendingSum(int[] nums)
        {
            int maxValue = nums[0], curValue = nums[0];
            int i = 0;
            for (i = 1; i < nums.Length; i++)
            {
                if (nums[i] > nums[i - 1])
                {
                    curValue += nums[i];
                }
                else
                {
                    if (curValue > maxValue)
                    {
                        maxValue = curValue;
                    }
                    curValue = nums[i];
                }
            }
            if (curValue > maxValue)
                maxValue = curValue;
            return maxValue;
        }


        public int MaxAscendingSum2(int[] nums)
        {
            int res = 0;
            int l = 0;
            while (l < nums.Length)
            {
                int cursum = nums[l++];
                while (l < nums.Length && nums[l] > nums[l - 1])
                {
                    cursum += nums[l++];
                }
                res = Math.Max(res, cursum);
            }
            return res;
        }


    }
}
