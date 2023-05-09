using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo962
{
    public class Class962
    {
        public int MaxWidthRamp(int[] nums)
        {
            int n = nums.Length;
            int[] stk = new int[n];
            int r = 0;
            for (int i = 0; i < n; i++)
            {
                if (r == 0 || nums[stk[r - 1]] > nums[i])
                {
                    stk[r++] = i;
                }
            }

            int res = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                while (r != 0 && nums[stk[r - 1]] <= nums[j])
                {
                    int i = stk[--r];
                    res = Math.Max(res, j - i);
                }
            }

            return res;
        }
    }
}
