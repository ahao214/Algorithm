using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo481
{
    public class Class481
    {
        //双指针
        public int MagicalString(int n)
        {
            if (n < 4)
            {
                return 1;
            }
            char[] s = new char[n];
            s[0] = '1';
            s[1] = '2';
            s[2] = '2';
            int res = 1;
            int i = 2;
            int j = 3;
            while (j < n)
            {
                int size = s[i] - '0';
                int num = 3 - (s[j - 1] - '0');
                while (size > 0 && j < n)
                {
                    s[j] = (char)('0' + num);
                    if (num == 1)
                    {
                        ++res;
                    }
                    ++j;
                    --size;
                }
                ++i;
            }
            return res;
        }
    }
}
