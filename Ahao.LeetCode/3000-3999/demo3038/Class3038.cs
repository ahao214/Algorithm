using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._3000_3999.demo3038
{
    internal class Class3038
    {
        public int MaxOperations(int[] nums)
        {
            int n = nums.Length;
            int res = 0;
            for (int i = 1; i < n; i += 2)
            {
                if (nums[i] + nums[i - 1] != nums[1] + nums[0])
                {
                    break;
                }
                res++;
            }
            return res;

        }
    }
}
