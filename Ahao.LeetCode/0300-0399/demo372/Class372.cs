using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo372
{
    /// <summary>
    /// 372. 超级次方
    /// </summary>
    public class Class372
    {
        public int SuperPow(int a, int[] b)
        {
            if (b.Length == 0)
            {
                return 1;
            }

            int last = b[b.Length - 1];
            int l = 1;
            for (int i = 1; i <= last; i++)
            {
                l = l * a % 1337;
            }

            int tmp = SuperPow(a, b.Take(b.Length - 1).ToArray());
            int f = 1;
            for (int i = 1; i <= 10; i++)
            {
                f = f * tmp % 1337;
            }
            return f * l % 1337;
        }
    }
}
