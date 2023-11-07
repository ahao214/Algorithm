using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2609
{
    public class Class2609
    {
        public int FindTheLongestBalancedSubstring(string s)
        {
            int res = 0;
            if (string.IsNullOrEmpty(s) || s.Length == 0)
            {
                return 0;
            }

            char[] chars = s.ToCharArray();
            int countZero = 0;
            int n = chars.Length;
            int count = 0;           
            for (int i = 0; i < n; i++)
            {
                if (chars[i] == '0')
                {
                    countZero++;
                    count++;
                }
                else
                {
                    if (countZero > 0)
                    {
                        countZero--;
                        count++;
                    }
                }
                if (countZero == 0)
                {
                    res = Math.Max(res, count);
                    count = 0;
                }
            }

            return res;
        }
    }
}
