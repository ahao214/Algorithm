using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 598. 范围求和 II
    /// </summary>
    public class Class589
    {
        public int MaxCount(int m, int n, int[][] ops)
        {
            int mina = m;
            int minb = n;
            foreach (int[] p in ops)
            {
                mina = Math.Min(mina, p[0]);
                minb = Math.Min(minb, p[1]);
            }
            return mina * minb;
        }
    }
}
