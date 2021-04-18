using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 如何判断1024!末尾有多少个0
    /// </summary>
    public class TestZeroCount
    {
        public static int ZeroCount(int n)
        {
            int count = 0;
            while (n > 0)
            {
                n = n / 5;
                count += n;
            }
            return count;
        }
    }
}
