using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo724
{
    public class Class724
    {
        public int PivotIndex(int[] nums)
        {
            int sum = nums.Sum();
            int total = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                total += nums[i];
                if (total == sum)
                    return i;
                sum = sum - nums[i];
            }
            return -1;
        }
    }
}
