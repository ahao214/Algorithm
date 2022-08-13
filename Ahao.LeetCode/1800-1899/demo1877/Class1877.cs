using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1877
{
    public class Class1877
    {
        public int MinPairSum(int[] nums)
        {
            Array.Sort(nums);
            int res = 0;
            for (int i = 0, j = nums.Length - 1; i < j; i++, j--)
            {
                res = Math.Max(res, nums[i] + nums[j]);
            }
            return res;
        }
    }
}
