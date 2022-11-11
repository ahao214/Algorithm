using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1704
{
    public class Class1704
    {
        public bool HalvesAreAlike(string s)
        {
            string a = s.Substring(0, s.Length / 2);
            string b = s.Substring(s.Length / 2);
            string h = "aeiouAEIOU";
            int sum1 = 0, sum2 = 0;
            foreach (char c in a)
            {
                if (h.IndexOf(c) >= 0)
                {
                    sum1++;
                }
            }
            foreach (char c in b)
            {
                if (h.IndexOf(c) >= 0)
                {
                    sum2++;
                }
            }
            return sum1 == sum2;
        }
    }
}
