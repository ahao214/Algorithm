using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6200_6299.demo6285
{
    public class Class6285
    {
        public long MaxKelements(int[] nums, int k)
        {
            long res = 0;
            while (k > 0)
            {
                Array.Sort(nums);
                res += nums[nums.Length-1];
                
            }

            return res;
        }
    }
}
