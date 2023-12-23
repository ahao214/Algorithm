using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1900_1999.demo1954
{
    public class Class1954
    {

        public long MinimumPerimeter(long neededApples)
        {
            long n = 1;
            while (2 * n * (n + 1) * (2 * n + 1) < neededApples)
            {
                n++;
            }
            return n * 8;
        }


        public long MinimumPerimeter2(long neededApples)
        {
            long left = 1, right = 100000, ans = 0;
            while (left <= right)
            {
                long mid = (left + right) / 2;
                if (2 * mid * (mid + 1) * (mid * 2 + 1) >= neededApples)
                {
                    ans = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return ans * 8;
        }


        public long minimumPerimeter(long neededApples)
        {
            long side = 0;
            long totalApples = 0;
            while (totalApples < neededApples)
            {
                side += 2;
                totalApples += 3 * side * side;
            }
            return side * 4;
        }


    }
}
