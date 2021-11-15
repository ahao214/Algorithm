using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1877. 数组中最大数对和的最小值
    /// </summary>
    public class MinPairSum
    {
        public int Method(int[] nums)
        {
            int result = 0;
            Array.Sort(nums);
            int len = nums.Length;
            for (int i = 0; i < len / 2; i++)
            {
                result = Math.Max(result, nums[i] + nums[len - i - 1]);
            }

            return result;
        }
    }
}
