using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2544
{
    internal class Class2544
    {

        public int AlternateDigitSum(int n)
        {
            int res = 0, sign = 1;
            while (n > 0)
            {
                res += n % 10 * sign;
                sign = -sign;
                n /= 10;
            }
            return res * -sign;
        }

    }
}
