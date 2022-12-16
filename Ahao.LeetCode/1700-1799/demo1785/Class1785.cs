using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1785
{
    public class Class1785
    {
        public int MinElements(int[] nums, int limit, int goal)
        {
            long sum = 0;
            foreach (int x in nums)
            {
                sum += x;
            }
            long diff = Math.Abs(sum - goal);
            return (int)((diff + limit - 1) / limit);
        }

    }
}
