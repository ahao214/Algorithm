using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2520
{
    public class Class2520
    {
        public int CountDigits(int num)
        {
            int res = 0;
            int cur = num;
            while (num != 0)
            {
                int n = num % 10;
                if (cur % n == 0)
                {
                    res++;
                }
                num /= 10;
            }
            return res;

        }

    }
}
