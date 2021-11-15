using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 485.最大连续1的个数
    /// </summary>
    public class FindMaxConsecutiveOnes
    {
        public int Method(int[] nums)
        {
            int result = 0;
            int count = 0;
            int maxValue = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] == 1)
                {
                    count++;
                }
                else
                {
                    result = maxValue > count ? maxValue : count;
                    maxValue = result;
                    count = 0;
                }
            }
            return result = result > count ? result : count;
        }
    }
}
