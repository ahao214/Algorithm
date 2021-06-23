using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 剑指 Offer 15. 二进制中1的个数
    /// </summary>
    public class HammingWeight
    {
        public int Method(uint n)
        {
            int res = 0;
            while (n != 0)
            {
                n &= n - 1;
                res++;
            }
            return res;
        }
    }
}
