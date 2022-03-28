using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo540
{
    public class Class540
    {
        public int SingleNonDuplicate(int[] nums)
        {
            int res = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                res ^= nums[i];
            }
            return res;
        }
    }
}
