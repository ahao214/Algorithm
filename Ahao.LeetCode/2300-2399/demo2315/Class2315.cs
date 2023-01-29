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



        public int CountAsterisks2(string s)
        {
            int flag = 0;
            int res = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '|')
                {
                    flag++;
                }
                if (flag % 2 == 0 && s[i] == '*')
                {
                    res++;
                }

            }
            return res;
        }


    }
}
