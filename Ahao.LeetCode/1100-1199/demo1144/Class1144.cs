using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1144
{
    public class Class1144
    {
        public int MovesToMakeZigzag(int[] nums)
        {
            int odd = 0;
            int even = 0;
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                int one = (i > 0 && nums[i] >= nums[i - 1]) ? (nums[i] - nums[i - 1] + 1) : 0;
                int two = (i < n - 1 && nums[i] >= nums[i + 1]) ? (nums[i] - nums[i + 1] + 1) : 0;
                if (i % 2 == 0)
                    even += Math.Max(one, two);
                else
                    odd += Math.Max(one, two);
            }

            return Math.Min(odd, even);
        }

    }
}
