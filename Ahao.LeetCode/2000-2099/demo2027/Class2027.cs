using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2000_2099.demo2027
{
    public class Class2027
    {
        public int MinimumMoves(string s)
        {
            int covered = -1, res = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == 'X' && i > covered)
                {
                    res++;
                    covered = i + 2;
                }
            }
            return res;
        }
    }
}
