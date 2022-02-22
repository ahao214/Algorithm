using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo29
{
    /*
     29. 两数相除
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
     */
    public class Class29
    {
        public int Divide(int dividend, int divisor)
        {
            if (divisor == 0) throw new DivideByZeroException();
            if (dividend == 0)
                return 0;
            var sign = 1;
            if (dividend > 0)
            {
                sign = -sign;
                dividend = -dividend;
            }
            if (divisor > 0)
            {
                sign = -sign;
                divisor = -divisor;
            }

            var result = 0;
            var n = -1;

            while (divisor >= (int.MinValue >> 1))
            {
                divisor <<= 1;
                n <<= 1;
            }

            while (true)
            {
                if (dividend <= divisor)
                {
                    result += n;
                    dividend -= divisor;
                }
                if (n == -1) break;
                divisor >>= 1;
                n >>= 1;
            }
            if (sign == 1)
            {
                return result == int.MinValue ? int.MaxValue : -result;
            }

            return result;
        }
    }
}
