using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo9
{
    /*
     9. 回文数
    给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 
    回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
    例如，121是回文，而 123 不是。
     */
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
