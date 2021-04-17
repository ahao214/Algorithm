using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 判断一个自然数是否是某个数的二次方
    /// </summary>
    public class TestIsPowerN
    {
        /// <summary>
        /// 构造法
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
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

        /// <summary>
        /// "与"操作法
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static bool IsPowerNT(int n)
        {
            if (n < 1)
                return false;
            int m = n & (n - 1);
            return m == 0;
        }

    }
}
