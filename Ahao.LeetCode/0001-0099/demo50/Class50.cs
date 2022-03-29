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

        public double MyPow2(double x, int n)
        {
            double ans = 1;
            double t = x;
            while (n != 0)
            {
                if ((n & 1) != 0)
                {
                    ans *= t;
                }
                t *= t; //x^2   x^4   x^8 
                n >>= 1;
            }
            return ans;
        }

        //x的n次方，n可能是负数
        public double pow(double x, int n)
        {
            if (n == 0)
                return 1D;
            int p = Math.Abs(n == int.MinValue ? n + 1 : n);
            double t = x;
            double ans = 1D;
            while (p != 0)
            {
                if ((p & 1) != 0)
                {
                    ans *= t;
                }
                p >>= 1;
                t = t * t;
            }
            if (n == int.MinValue)
                ans *= x;
            return n < 0 ? (1D / ans) : ans;

        }
    }
}
