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
            for (int i = 1; i <= a; i++)
            {
                if (a % i == 0)
                    lst.Add(i);
            }

            for (int i = 1; i <= b; i++)
            {
                if (b % i == 0 && lst.Contains(i))
                    res++;
            }
            return res;
        }


        public int CommonFactors2(int a, int b)
        {
            int ans = 0;
            for (int x = 1; x <= Math.Min(a, b); ++x)
            {
                if (a % x == 0 && b % x == 0)
                {
                    ++ans;
                }
            }
            return ans;
        }


        public int CommonFactors3(int a, int b)
        {
            int c = GCD(a, b), ans = 0;
            for (int x = 1; x * x <= c; ++x)
            {
                if (c % x == 0)
                {
                    ++ans;
                    if (x * x != c)
                    {
                        ++ans;
                    }
                }
            }
            return ans;
        }

        public int GCD(int a, int b)
        {
            while (b != 0)
            {
                a %= b;
                a ^= b;
                b ^= a;
                a ^= b;
            }
            return a;
        }
    }
}
