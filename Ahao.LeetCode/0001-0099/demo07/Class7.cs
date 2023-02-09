using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo7
{
    public class Class7
    {
        public int Reverse(int x)
        {
            var n = 0;
            try
            {
                while (x != 0)
                {
                    var d = x % 10;
                    checked
                    {
                        n = n * 10 + d;
                        x /= 10;
                    }
                }
            }
            catch (OverflowException)
            {
                return 0;
            }
            return n;
        }
    }
}
