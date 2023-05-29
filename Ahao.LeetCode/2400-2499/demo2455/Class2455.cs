using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2455
{
    public class Class2455
    {

        public int AverageValue(int[] nums)
        {
            int total = 0;
            int count = 0;
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                int a = nums[i];
                if (a % 6 == 0)
                {
                    total += a;
                    count++;
                }
            }
            return count > 0 ? total / count : 0;
        }




    }
}
