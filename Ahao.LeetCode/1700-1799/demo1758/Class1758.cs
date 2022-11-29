using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1758
{
    public class Class1758
    {
        public int MinOperations(string s)
        {
            int cnt = 0;
            for (int i = 0; i < s.Length; i++)
            {
                char c = s[i];
                if (c != (char)('0' + i % 2))
                {
                    cnt++;
                }
            }
            return Math.Min(cnt, s.Length - cnt);
        }
    }
}
