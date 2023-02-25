using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1247
{
    public class Class1247
    {
        public int MinimumSwap(string s1, string s2)
        {
            int xy = 0, yx = 0;
            int n = s1.Length;
            for (int i = 0; i < n; i++)
            {
                char a = s1[i], b = s2[i];
                if (a == 'x' && b == 'y')
                {
                    xy++;
                }
                if (a == 'y' && b == 'x')
                {
                    yx++;
                }
            }
            if ((xy + yx) % 2 == 1)
            {
                return -1;
            }
            return xy / 2 + yx / 2 + xy % 2 + yx % 2;
        }
    }
}
