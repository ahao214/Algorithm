using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo13
{
    public class Class13
    {
        private readonly Dictionary<char, int> dic = new Dictionary<char, int>() {
            ['I'] = 1,
            ['V'] = 5,
            ['X'] = 10,
            ['L'] = 50,
            ['C'] = 100,
            ['D'] = 500,
            ['M'] = 1000,
        };
        public int RomanToInt(string s)
        {
            var n = 0;
            var m = int.MaxValue;
            foreach (var ch in s)
            {
                var tmp = dic[ch];
                if (tmp > m)
                {
                    n -= m * 2;
                }
                n += tmp;
                m = tmp;
            }
            return n;
        }
    }
}
