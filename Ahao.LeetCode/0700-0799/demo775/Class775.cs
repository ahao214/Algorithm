using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo775
{
    public class Class775
    {
        public bool IsIdealPermutation(int[] nums)
        {
            int n = nums.Length, minSuff = nums[n - 1];
            for (int i = n - 3; i >= 0; i--)
            {
                if (nums[i] > minSuff)
                {
                    return false;
                }
                minSuff = Math.Min(minSuff, nums[i + 1]);
            }
            return true;
        }
    }
}
