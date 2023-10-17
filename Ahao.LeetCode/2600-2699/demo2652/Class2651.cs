using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2652
{
    internal class Class2652
    {

        public int SumOfMultiples(int n)
        {
            int result = 0;
            for (int i = 1; i <= n; i++)
            {
                if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
                {
                    result += i;
                }
            }
            return result;
        }




        public int f(int n, int m)
        {
            return (m + n / m * m) * (n / m) / 2;
        }
        public int SumOfMultiples2(int n)
        {
            return f(n, 3) + f(n, 5) + f(n, 7) - f(n, 3 * 5) - f(n, 3 * 7) - f(n, 5 * 7) + f(n, 3 * 5 * 7);
        }


    }
}
