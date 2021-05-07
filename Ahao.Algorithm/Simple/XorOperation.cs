using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1486. 数组异或操作
    /// </summary>
    public class XorOperation
    {
        public int Method(int n, int start)
        {
            if (n == 1)
                return start;
            int result = start;
            int tmp;
            for (int i = 1; i < n; i++)
            {
                tmp = start + 2 * i;
                result = result ^ tmp;
            }
            return result;
        }
    }
}
