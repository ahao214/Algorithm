using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1403
{
    public class Class1403
    {
        public IList<int> MinSubsequence(int[] nums)
        {
            int total = nums.Sum();
            Array.Sort(nums);
            IList<int> res = new List<int>();
            int curr = 0;
            for (int i = nums.Length - 1; i >= 0; --i)
            {
                curr += nums[i];
                res.Add(nums[i]);
                if (curr + curr > total)
                    break;
            }
            return res;
        }

    }
}
