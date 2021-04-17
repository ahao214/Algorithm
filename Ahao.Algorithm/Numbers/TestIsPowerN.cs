using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 判断一个自然数是否是某个数的二次方
    /// </summary>
    public class TestIsPowerN
    {
        public static bool IsPowerN(int n)
        {
            if (n < 1)
                return false;
            int i = 1;
            while (i <= n)
            {
                if (i == n)
                    return true;
                i <<= 1;
            }
            return false;
        }
    }
}
