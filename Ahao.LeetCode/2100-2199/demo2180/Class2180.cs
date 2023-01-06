using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2100_2199.demo2180
{
    public class Class2180
    {
        public int CountEven(int num)
        {
            int res = 0;
            for (int i = 1; i <= num; i++)
            {
                int x = i, sum = 0;
                while (x != 0)
                {
                    sum += x % 10;
                    x /= 10;
                }
                if (sum % 2 == 0)
                {
                    res++;
                }
            }
            return res;
        }
    }
}
