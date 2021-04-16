using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 反转整数
    /// </summary>
    public class TestReverseInteger
    {
        public static int ReverseInteger(int n)
        {
            long m = 0;
            while (n != 0)
            {
                m = m * 10 + n % 10;
                n = n / 10;
            }
            if (m > int.MaxValue)
            {
                return 0;
            }
            else
            {
                return (int)m;
            }
        }

    }
}
