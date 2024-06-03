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



        public int[] DistributeCandies2(int candies, int num_people)
        {
            int n = num_people;
            int p = (int)(Math.Sqrt(2 * candies + 0.25) - 0.5);
            int remaining = (int)(candies - (p + 1) * p * 0.5);
            int rows = p / n, cols = p % n;

            int[] d = new int[n];
            for (int i = 0; i < n; ++i)
            {
                // complete rows
                d[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * n;
                // cols in the last row
                if (i < cols)
                {
                    d[i] += i + 1 + rows * n;
                }
            }
            // remaining candies        
            d[cols] += remaining;
            return d;
        }


    }
}
