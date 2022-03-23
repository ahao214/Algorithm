using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1332
{
    public class Class1332
    {
        public int RemovePalindromeSub(string s)
        {
            int n = s.Length;
            for (int i = 0; i < n / 2; ++i)
            {
                if (s[i] != s[n - 1 - i])
                {
                    return 2;
                }
            }
            return 1;
        }
    }
}
