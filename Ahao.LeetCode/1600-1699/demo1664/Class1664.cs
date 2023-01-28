using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1664
{
    public class Class1664
    {

        public int WaysToMakeFair(int[] nums)
        {
            int odd1 = 0, even1 = 0;
            int odd2 = 0, even2 = 0;
            for (int i = 0; i < nums.Length; ++i)
            {
                if ((i & 1) != 0)
                {
                    odd2 += nums[i];
                }
                else
                {
                    even2 += nums[i];
                }
            }
            int res = 0;
            for (int i = 0; i < nums.Length; ++i)
            {
                if ((i & 1) != 0)
                {
                    odd2 -= nums[i];
                }
                else
                {
                    even2 -= nums[i];
                }
                if (odd1 + even2 == odd2 + even1)
                {
                    ++res;
                }
                if ((i & 1) != 0)
                {
                    odd1 += nums[i];
                }
                else
                {
                    even1 += nums[i];
                }
            }
            return res;
        }
    }
}
