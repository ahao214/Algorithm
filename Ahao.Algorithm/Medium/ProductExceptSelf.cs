using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 238.除自身以外数组的乘积
    /// </summary>
    public class ProductExceptSelf
    {
        public int[] Method(int[] nums)
        {
            int len = nums.Length;
            int[] output = new int[len];
            int p = 1;
            int cnt = 0;
            for (int i = 0; i < len; i++)
            {
                if (nums[i] == 0)
                {
                    cnt++;
                    if (cnt == 2) return output;
                    continue;
                }
                p *= nums[i];
            }
            for (int i = 0; i < len; i++)
            {
                if (nums[i] == 0)
                {
                    output[i] = p;
                    return output;
                }
            }
            for (int i = 0; i < len; i++)
            {
                output[i] = p / nums[i];
            }
            return output;
        }

    }
}
