using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 643.子数组最大平均数-1
    /// </summary>
    public class FindMaxAverage
    {
        public double Method(int[] nums, int k)
        {
            int sum = nums.Take(k).Sum();
            int maxVal = sum;
            int len = nums.Length;
            for (int i = 0; i < len - k; i++)
            {
                //减去头部的数字，加上尾部的数字
                sum = sum - nums[i] + nums[i + k];
                if (sum > maxVal)
                {
                    maxVal = sum;
                }
            }

            return maxVal / (double)k;
        }
    }
}
