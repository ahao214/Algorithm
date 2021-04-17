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
    public class TestIsPower
    {
        public static bool IsPower(int n)
        {
            int i;
            int m;
            if (n <= 0)
            {
                Console.WriteLine(n + "不是自然数");
                return false;
            }
            for (i = 1; i < n; i++)
            {
                m = i * i;
                if (m == n)
                {
                    return true;
                }
                else if (m > n)
                {
                    return false;
                }
            }
            return false;
        }
    }
}
