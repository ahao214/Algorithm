using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 53. 最大子序和
    /// </summary>
    public class MaxSubArray
    {
        public int Methd(int[] nums)
        {
            int result = nums[0];
            int sum = 0;
            foreach (int x in nums)
            {
                sum = x + Math.Max(sum, 0);
                result = Math.Max(result, sum);
            }
            return result;
        }
    }
}
