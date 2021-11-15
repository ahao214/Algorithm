using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1646. 获取生成数组中的最大值
    /// </summary>
    public class GetMaximumGenerated
    {
        public int Method(int n)
        {
            if (n == 0)
            {
                return 0;
            }
            if (n == 1)
            {
                return 1;
            }
            int[] nums = new int[n + 1];
            nums[0] = 0;
            nums[1] = 1;
            int maxNum = 1;
            for (int i = 1; i < n; i++)
            {
                if (2 * i <= n)
                {
                    nums[2 * i] = nums[i];
                }
                if (2 * i + 1 <= n)
                {
                    nums[2 * i + 1] = nums[i] + nums[i + 1];
                    maxNum = maxNum < nums[2 * i + 1] ? nums[2 * i + 1] : maxNum;
                }
                else
                {
                    break;
                }
            }
            return maxNum;
        }
    }
}
