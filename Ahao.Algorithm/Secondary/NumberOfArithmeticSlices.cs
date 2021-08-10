using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 413. 等差数列划分
    /// </summary>
    public class NumberOfArithmeticSlices
    {
        public int Method(int[] nums)
        {
            int result = 0;
            int len = nums.Length;
            if (len < 3)
            {
                return result;
            }
            int count = 0;
            for (int i = 1; i < len - 1; i++)
            {
                if (nums[i + 1] - nums[i] == nums[i] - nums[i - 1])
                {
                    count++;
                    result += count;
                }
                else
                {
                    count = 0;
                }
            }
            return result;
        }
    }
}
