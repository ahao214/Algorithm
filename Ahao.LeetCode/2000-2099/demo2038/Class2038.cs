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
    }
}
