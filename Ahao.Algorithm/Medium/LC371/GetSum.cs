using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 371.两整数之和
    /// </summary>
    public class GetSum
    {
        /// <summary>
        /// 给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public int Method(int a, int b)
        {
            int sum;
            int carry;
            sum = a ^ b;
            carry = (a & b) << 1;
            if (carry != 0)
            {
                return Method(sum, carry);
            }
            return sum;
        }
    }
}
