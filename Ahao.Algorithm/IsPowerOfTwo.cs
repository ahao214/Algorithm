using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 231. 2的幂   
    /// </summary>
    public class IsPowerOfTwo
    {
        public bool Method(int n)
        {
            //当n = 4时，二进制为：0100，n - 1 = 3，二进制为：0011，则：n & (n - 1) == 0
            //当n = 8时，为1000，n - 1 = 7，为0111，则n & (n - 1) == 0
            //再举个反例：当n = 5，为0101，n - 1为0100，则n & (n - 1) = 0100 = 4 != 0
            //从上面我们可以看出，凡是2的幂，均是二进制数的某一高位为1，且仅此高位为1，比如4，0100；8，1000。那么它的n - 1就变成了1所处的高位变成0，剩余低位变成1，如4 - 1,0011,8 - 1,0111，那么n & (n - 1)必为0
            if (n <= 0)
            {
                return false;
            }
            return (n & (n - 1)) == 0;
        }
    }
}
