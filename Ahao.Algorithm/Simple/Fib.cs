using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 剑指 Offer 10- I. 斐波那契数列
    /// </summary>
    public class Fib
    {
        public int Method(int n)
        {
            if (n < 2)
            {
                return n;
            }
            else
            {
                int a = 0;
                int b = 1;
                int sum = 0;
                for (int i = 2; i <= n; i++)
                {
                    sum = (a + b) % 1000000007;
                    a = b;
                    b = sum;
                }
                return sum;
            }
        }
    }
}
