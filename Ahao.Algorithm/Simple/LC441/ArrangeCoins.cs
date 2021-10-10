using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 441. 排列硬币
    /// </summary>
    public class ArrangeCoins
    {
        public int Method(int n)
        {
            int result = 1;
            while (n >= result)
            {
                n -= result;
                result++;
            }
            return result - 1;
        }
    }
}
