using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 326.3的幂
    /// </summary>
    public class IsPowerOfThree
    {
        public bool Method(int n)
        {
            if (n == 1 || n == 3)
            {
                return true;
            }
            else if (n == 0 || n / 3 * 3 != n)//n不是3的倍数
            {
                return false;
            }
            return Method(n / 3);
        }
    }
}
