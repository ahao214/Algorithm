using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo9
{
    public class Class9
    {
        public bool IsPalindrome(int x)
        {
            if (x < 0)
                return false;
            var s = x.ToString();
            return s.Reverse().SequenceEqual(s);
        }

        public bool IsPalindrome1(int x)
        {
            if (x < 0) return false;
            if (x % 10 == 0) return x == 0;
            var r = 0;
            while (x > r)
            {
                r = r * 10 + x % 10;
                x /= 10;
            }
            return x == r || x == r / 10;
        }
    }
}
