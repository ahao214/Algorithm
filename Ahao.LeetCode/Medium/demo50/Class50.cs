using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo50
{
    /*
     50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n ）。
     */
    public class Class50
    {
        public double MyPow(double x, int n)
        {
            if (n == 0)
                return 1;
            if (n < 0)
            {
                x = 1 / x;
                n = n == int.MinValue ? 0 : -n;
            }
            var result = 1.0d;
            var power = 1;
            while ((power <= n || n == 0) && power > 0)
            {
                if ((n & power) != 0)
                    result *= x;
                power <<= 1;
                x *= x;
            }
            if (n == 0)
                result *= x;
            return result;
        }
    }
}
