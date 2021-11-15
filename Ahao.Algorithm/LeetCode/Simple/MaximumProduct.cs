using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 628.三个数的最大乘积
    /// </summary>
    public class MaximumProduct
    {
        public int Method(int[] nums)
        {
            int maxValue;
            Array.Sort(nums);
            var length = nums.Length;

            //最大的三个正整数的乘积
            var leftValue = nums[length - 1] * nums[length - 2] * nums[length - 3];
            //最大的两个负数和最大的正整数的乘积
            var rightValue = nums[0] * nums[1] * nums[length - 1];
            if (leftValue > rightValue)
                maxValue = leftValue;
            else
                maxValue = rightValue;

            return maxValue;
        }
    }
}
