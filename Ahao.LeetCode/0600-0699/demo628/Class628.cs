using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo628
{
    public class Class628
    {
        public int MaximumProduct(int[] nums)
        {
            Array.Sort(nums);
            int n = nums.Length;
            return Math.Max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
        }

        /// <summary>
        /// 线性扫描
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MaximumProduct2(int[] nums)
        {
            int min1 = int.MaxValue;
            int min2 = int.MaxValue;
            int max1 = int.MinValue;
            int max2 = int.MinValue;
            int max3 = int.MinValue;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] < min1)
                {
                    min2 = min1;
                    min1 = nums[i];
                }
                else if (nums[i] < min2)
                {
                    min2 = nums[i];
                }
                if (nums[i] > max1)
                {
                    max3 = max2;
                    max2 = max1;
                    max1 = nums[i];
                }
                else if (nums[i] > max2)
                {
                    max3 = max2;
                    max2 = nums[i];
                }
                else if (nums[i] > max3)
                {
                    max3 = nums[i];
                }
            }
            return Math.Max(min1 * min2 * max1, max1 * max2 * max3);
        }
    }
}
