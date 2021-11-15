using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 152. 乘积最大子数组
    /// </summary>
    public class MaxProduct
    {
        public int Method(int[] nums)
        {
            if (nums == null)
                return 0;

            int result = nums[0];

            int curMax = nums[0];
            int curMin = nums[0];
            int tmpMax;
            int tmpMin;
            for (int i = 1; i < nums.Length; i++)
            {
                int n = nums[i];
                tmpMax = curMax * n;
                tmpMin = curMin * n;

                curMax = Math.Max(Math.Max(tmpMax, tmpMin), n);
                curMin = Math.Min(Math.Min(tmpMax, tmpMin), n);

                result = Math.Max(result, curMax);
            }
            return result;
        }
    }
}
