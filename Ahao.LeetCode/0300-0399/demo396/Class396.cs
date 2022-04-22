using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo396
{
    public class Class396
    {
        public int MaxRotateFunction(int[] nums)
        {
            int f = 0, n = nums.Length, numSum = nums.Sum();
            for (int i = 0; i < n; i++)
            {
                f += i * nums[i];
            }
            int res = f;
            for (int i = n - 1; i > 0; i--)
            {
                f += numSum - n * nums[i];
                res = Math.Max(res, f);
            }
            return res;
        }
    }
}
