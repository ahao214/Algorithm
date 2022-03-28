using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo693
{
    public class Class693
    {
        public bool HasAlternatingBits(int n)
        {
            int prev = -1;
            while (n != 0)
            {
                int cur = n % 2;
                if (cur == prev)
                {
                    return false;
                }
                prev = cur;
                n /= 2;
            }
            return true;
        }

        public bool HasAlternatingBits2(int n)
        {
            int a = n ^ (n >> 1);
            return (a & (a + 1)) == 0;
        }
    }
}
