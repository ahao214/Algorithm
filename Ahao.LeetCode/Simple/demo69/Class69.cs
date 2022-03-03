using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo69
{
    /*
     69. x 的平方根 
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5
     */
    public class Class69
    {
        private static readonly int MAX = (int)Math.Sqrt(int.MaxValue);
        public int MySqrt(int x)
        {
            var low = 0;
            var high = x;
            while (low <= high)
            {
                var mid = low + (high - low) / 2;
                if (mid > MAX)
                {
                    high = mid - 1;
                    continue;
                }
                var m2 = mid * mid;
                if (m2 == x)
                    return mid;
                if (m2 < x)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return low - 1;
        }
    }
}
