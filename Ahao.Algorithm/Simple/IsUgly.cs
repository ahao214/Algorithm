using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 363.丑数
    /// 丑数就是只包含质因数 2, 3, 5 的正整数
    /// 1 是丑数
    /// </summary>
    public class IsUgly
    {
        public bool Method(int num)
        {
            bool result = false;
            if (num < 1)
            {
                return result;
            }
            while (num % 5 == 0)
            {
                num = num / 5;
            }
            while (num % 3 == 0)
            {
                num = num / 3;
            }
            while (num % 2 == 0)
            {
                num = num / 2;
            }

            result = num == 1;

            return result;
        }
    }
}
