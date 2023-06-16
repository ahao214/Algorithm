using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2481
{
    public class Class2481
    {
        public int NumberOfCuts(int n)
        {
            if (n == 1)
            {
                return 0;
            }
            if (n % 2 == 0)
            {
                return n / 2;
            }
            return n;

        }
    }
}
