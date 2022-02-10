using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo10
{
    /*
     10. 正则表达式匹配
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
     */
    public class Class10
    {
        public bool IsMatch(string s, string p)
        {
            if (s == null) return p == null;
            if (p == null) return false;
            return IsMatch(s, 0, p, 0);
        }

        private bool IsMatch(string s, int si, string p, int pi)
        {
            if (pi == p.Length) return si == s.Length;
            if (pi + 1 < p.Length)
            {
                if (p[pi + 1] == '*')
                {
                    return IsMatch(s, si, p, pi + 2) || si < s.Length && (s[si] == p[pi] || p[pi] == '.') && IsMatch(s, si + 1, p, pi);
                }
            }
            return si < s.Length && (s[si] == p[pi] || p[pi] == '.') && IsMatch(s, si + 1, p, pi + 1);
        }
    }
}
