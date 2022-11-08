using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1684
{
    public class Class1684
    {
        public int CountConsistentStrings(string allowed, string[] words)
        {
            int mask = 0;
            foreach (char c in allowed)
            {
                mask |= 1 << (c - 'a');
            }
            int res = 0;
            foreach (string word in words)
            {
                int mask1 = 0;
                foreach (char c in word)
                {
                    mask1 |= 1 << (c - 'a');
                }
                if ((mask1 | mask) == mask)
                {
                    res++;
                }
            }
            return res;
        }

    }
}
