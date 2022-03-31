using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo300
{
    public class Class300
    {
        public int LengthOfLIS(int[] nums)
        {
            if (nums.Length == 0 || nums == null)
            {
                return 0;
            }

            int[] ends = new int[nums.Length];
            ends[0] = nums[0];
            int right = 0;
            int l = 0;
            int r = 0;
            int m = 0;
            int max = 1;
            for (int i = 1; i < nums.Length; i++)
            {
                l = 0;
                r = right;
                while (l <= r)
                {
                    m = (l + r) / 2;
                    if (nums[i] > ends[m])
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m - 1;
                    }
                }
                right = Math.Max(right, l);
                ends[l] = nums[i];
                max = Math.Max(max, l + 1);
            }
            return max;

        }
    }
}
