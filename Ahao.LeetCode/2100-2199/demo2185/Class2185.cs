using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2100_2199.demo2185
{
    public class Class2185
    {
        public int PrefixCount(string[] words, string pref)
        {
            int res = 0;
            int len = pref.Length;
            for (int i = 0; i < words.Length; i++)
            {
                if (words[i].Length >= len)
                {
                    if (words[i].Substring(0, len) == pref)
                        res++;
                }
            }

            return res;
        }
    }
}
