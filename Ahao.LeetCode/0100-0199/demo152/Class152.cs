using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo152
{
    public class Class152
    {
        public int MaxProduct(int[] nums)
        {
            int n = nums.Length;
            int[] dpMax = new int[n];
            int[] dpMin = new int[n];
            dpMax[0] = nums[0];
            dpMin[0] = nums[0];
            int ans = nums[0];
            for (int i = 1; i < n; i++)
            {
                int p1 = nums[i];
                int p2 = nums[i] * dpMax[i - 1];
                int p3 = nums[i] * dpMin[i - 1];
                dpMax[i] = Math.Max(Math.Max(p1, p2), p3);
                dpMin[i] = Math.Min(Math.Min(p1, p2), p3);
                ans = Math.Max(ans, dpMax[i]);
            }
            return ans;

        }
    }
}
