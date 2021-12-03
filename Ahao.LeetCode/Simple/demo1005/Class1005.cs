using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    /// <summary>
    /// 1005. K 次取反后最大化的数组和
    /// </summary>
    public class Class1005
    {
        public int LargestSumAfterKNegations(int[] nums, int k)
        {
            int n = nums.Length;

            //根据数值的绝对值排序
            Array.Sort(nums, (x, y) =>
            {
                return Math.Abs(x) - Math.Abs(y);
            });
            for (int i = n - 1; i >= 0; i--)
            {
                if (nums[i] < 0 && k > 0)
                {
                    nums[i] = -1 * nums[i];
                    k--;
                }
            }
            if (k % 2 == 1)
            {
                nums[0] = -1 * nums[0];
            }
            return nums.Sum();
        }
    }
}
