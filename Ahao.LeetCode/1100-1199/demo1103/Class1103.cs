using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1103
{
    internal class Class1103
    {

        public int[] DistributeCandies(int candies, int num_people)
        {
            int[] ans = new int[num_people];
            int i = 0;
            while (candies != 0)
            {
                ans[i % num_people] += Math.Min(candies, i + 1);
                candies -= Math.Min(candies, i + 1);
                i += 1;
            }
            return ans;
        }

    }
}
