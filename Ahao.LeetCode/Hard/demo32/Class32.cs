using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo32
{
    /*
     32. 最长有效括号
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
     */
    public class Class32
    {
        public int LongestValidParentheses(string s)
        {
            if (string.IsNullOrEmpty(s))
            {
                return 0;
            }
            var lst = new List<Pair>(s.Length / 2 + 1);

            return lst.Count == 0 ? 0 : lst.Max(t => t.Length);
        }
    }

    struct Pair
    {
        public readonly int Left;
        public readonly int Length;
        public int BeforeLeft => Left - 1;
        public int AfterRight => Left + Length;

        public Pair(int left, int length)
        {
            Left = left;
            Length = length;
        }
    }

}
