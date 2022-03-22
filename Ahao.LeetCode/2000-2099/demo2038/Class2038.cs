using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2000_2099.demo2038
{
    public class Class2038
    {
        public bool WinnerOfGame(string colors)
        {
            int len = colors.Length;
            int na = 0, nb = 0, ta = 0, tb = 0;
            for (int i = 0; i < len; i++)
            {
                if (colors[i] == 'A')
                {
                    if (++ta >= 3)
                    {
                        na++;
                    }
                    tb = 0;
                }
                else
                {
                    if (++tb>= 3)
                    {
                        nb++;
                    }
                    ta = 0;
                }
            }
            return na > nb;
        }

        public bool WinnerOfGame2(string colors)
        {
            int[] freq = { 0, 0 };
            char cur = 'C';
            int cnt = 0;
            foreach (char c in colors)
            {
                if (c != cur)
                {
                    cur = c;
                    cnt = 1;
                }
                else
                {
                    cnt += 1;
                    if (cnt >= 3)
                    {
                        freq[cur - 'A'] += 1;
                    }
                }
            }
            return freq[0] > freq[1];
        }

    }
}
