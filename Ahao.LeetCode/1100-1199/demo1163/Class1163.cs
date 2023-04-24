using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1163
{
    public class Class1163
    {
        public string LastSubstring(string s)
        {
            int i = 0, j = 1, n = s.Length;
            while (j < n)
            {
                int k = 0;
                while (j + k < n && s[i + k] == s[j + k])
                {
                    k++;
                }
                if (j + k < n && s[i + k] < s[j + k])
                {
                    int t = i;
                    i = j;
                    j = Math.Max(j + 1, t + k + 1);
                }
                else
                {
                    j = j + k + 1;
                }
            }
            return s.Substring(i);
        }

    }
}
