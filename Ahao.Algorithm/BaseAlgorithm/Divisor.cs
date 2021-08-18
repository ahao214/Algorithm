using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.BaseAlgorithm
{
    /// <summary>
    /// 两个整数的最大公约数
    /// </summary>
    public class Divisor
    {
        public int Gcd(int a, int b)
        {
            while (b != 0)
            {
                int c = a % b;
                a = b;
                b = c;
            }
            return a;
        }
    }
}
