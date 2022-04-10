using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo357
{
    public class Class357
    {
        public int CountNumbersWithUniqueDigits(int n)
        {
            if (n == 0)
                return 1;
            if (n == 1)
                return 10;
            int res = 10, cur = 9;
            for (int i = 0; i < n - 1; i++)
            {
                cur *= 9 - i;
                res += cur;
            }

            return res;
        }
    }
}
