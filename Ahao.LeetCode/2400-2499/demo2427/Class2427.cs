using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2427
{
    public class Class2427
    {
        public int CommonFactors(int a, int b)
        {
            int res = 0;
            List<int> lst = new List<int>();
            for(int i = 1;i<= a; i++)
            {
                if (a % i == 0)
                    lst.Add(i);
            }

            for(int i = 1;i <= b; i++)
            {
                if (b % i == 0 && lst.Contains(i))
                    res++;
            }
            return res;
        }
    }
}
