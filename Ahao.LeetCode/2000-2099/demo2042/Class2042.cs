using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2000_2099.demo2042
{
    public class Class2042
    {
        public bool AreNumbersAscending(string s)
        {
            int pre = 0, pos = 0;
            while (pos < s.Length)
            {
                if (char.IsDigit(s[pos]))
                {
                    int cur = 0;
                    while (pos < s.Length && char.IsDigit(s[pos]))
                    {
                        cur = cur * 10 + s[pos] - '0';
                        pos++;
                    }
                    if (cur <= pre)
                    {
                        return false;
                    }
                    pre = cur;
                }
                else
                {
                    pos++;
                }
            }
            return true;
        }
    }
}
