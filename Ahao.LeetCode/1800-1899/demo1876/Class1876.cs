using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1876
{
    public class Class1876
    {
        public int CountGoodSubstrings(string s)
        {
            int res = 0;
            for (int i = 0; i + 2 < s.Length; i++)
            {
                int a = i, b = i + 1, c = i + 2;
                if (s[a] != s[b] && s[b] != s[c] && s[a] != s[c])
                    res++;
            }
            return res;
        }
    }
}
