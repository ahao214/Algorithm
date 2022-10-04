using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo921
{
    public class Class921
    {
        public int MinAddToMakeValid(string s)
        {
            int res = 0;
            int leftCount = 0;
            int length = s.Length;
            for (int i = 0; i < length; i++)
            {
                char c = s[i];
                if (c == '(')
                {
                    leftCount++;
                }
                else
                {
                    if (leftCount > 0)
                    {
                        leftCount--;
                    }
                    else
                    {
                        res++;
                    }
                }
            }
            res += leftCount;
            return res;
        }
    }
}
