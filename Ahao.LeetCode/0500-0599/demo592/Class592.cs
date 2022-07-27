using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo592
{
    public class Class592
    {
        public string FractionAddition(string expression)
        {
            long denominator = 0, numerator = 1; // 分子，分母
            int index = 0, n = expression.Length;
            while (index < n)
            {
                // 读取分子
                long denominator1 = 0, sign = 1;
                if (expression[index] == '-' || expression[index] == '+')
                {
                    sign = expression[index] == '-' ? -1 : 1;
                    index++;
                }
                while (index < n && char.IsDigit(expression[index]))
                {
                    denominator1 = denominator1 * 10 + expression[index] - '0';
                    index++;
                }
                denominator1 = sign * denominator1;
                index++;

                // 读取分母
                long numerator1 = 0;
                while (index < n && char.IsDigit(expression[index]))
                {
                    numerator1 = numerator1 * 10 + expression[index] - '0';
                    index++;
                }

                denominator = denominator * numerator1 + denominator1 * numerator;
                numerator *= numerator1;
            }
            if (denominator == 0)
            {
                return "0/1";
            }
            long g = GCD(Math.Abs(denominator), numerator); // 获取最大公约数
            return (denominator / g).ToString() + "/" + (numerator / g).ToString();
        }

        public long GCD(long a, long b)
        {
            long remainder = a % b;
            while (remainder != 0)
            {
                a = b;
                b = remainder;
                remainder = a % b;
            }
            return b;
        }

    }
}
