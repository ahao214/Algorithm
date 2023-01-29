using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2315
{
    public class Class2315
    {
        public int CountAsterisks(string s)
        {
            bool valid = true;
            int res = 0;
            foreach (char c in s)
            {
                if (c == '|')
                {
                    valid = !valid;
                }
                else if (c == '*' && valid)
                {
                    res++;
                }
            }
            return res;
        }
    }
}
