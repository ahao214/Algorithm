using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 416. 分割等和子集
    /// </summary>
    public class CanPartition
    {
        public bool Method(int[] nums)
        {
            if (nums.Length == 0 || nums.Length == 1)
            {
                return false;
            }

            if (nums.Length == 2)
            {
                return nums[0] == nums[1];
            }

            int sum = nums.Sum();      
            if (sum % 2 != 0)
            {
                return false;
            }
            sum = sum / 2;
            bool[] f = new bool[sum + 1];
            f[0] = true;
            if (nums[0] <= sum)
            {
                f[nums[0]] = true;
            }
            for (int i = 1; i < nums.Length; i++)
            {
                for (int j = sum; j >= nums[i]; j--)
                {
                    if (f[sum])
                    {
                        return true;
                    }
                    f[j] = f[j] || f[j - nums[i]];
                }
            }
            return f[sum];


        }
    }
}
