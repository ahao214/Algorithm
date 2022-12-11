using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1827
{
    public class Class1827
    {
        public int MinOperations(int[] nums)
        {
            int n = nums.Length;
            if (n == 1)
                return 0;
            int max = nums[0];
            int res = 0;
            for (int i = 1; i < nums.Length; i++)
            {
                if (nums[i] <= max)
                {
                    res += max + 1 - nums[i];
                    ++max;
                }
                else
                {
                    max = nums[i];
                }
            }
            return res;
        }
    }
}
