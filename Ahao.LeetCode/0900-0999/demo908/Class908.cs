using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo908
{
    public class Class908
    {
        public class Solution
        {
            public int SmallestRangeI(int[] nums, int k)
            {
                int minNum = nums.Min();
                int maxNum = nums.Max();
                return maxNum - minNum <= 2 * k ? 0 : maxNum - minNum - 2 * k;
            }
        }
    }
}
