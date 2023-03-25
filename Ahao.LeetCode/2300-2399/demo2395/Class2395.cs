using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2395
{
    public class Class2395
    {
        public bool FindSubarrays(int[] nums)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length - 1; i++)
            {
                if (!dic.ContainsKey(nums[i] + nums[i + 1]))
                {
                    dic.Add(nums[i] + nums[i + 1], 1);
                }
                else
                {
                    return true;
                }
            }

            return false;
        }
    }
}
