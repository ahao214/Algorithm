using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo44
{
    /*
     44. 通配符匹配
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
     */
    public class Class44
    {
        public bool IsMatch(string s, string p)
        {
            if (s == null)
                throw new ArgumentException(nameof(s));
            if (p == null)
                throw new ArgumentException(nameof(s));
            var cache = new byte[s.Length, p.Length];
            return IsMatch(s, 0, p, 0, cache);
        }

        private bool IsMatch(string s, int si, string p, int pi, byte[,] cache)
        {
            if (pi == p.Length)
                return si == s.Length;
            if (si < s.Length && pi < p.Length && cache[si, pi] != 0)
                return cache[si, pi] == 1;
            if (si > s.Length)
                return false;
            bool res;
            var pch = p[pi];
            if (pch == '*')
            {
                res = IsMatch(s, si, p, pi + 1, cache) || IsMatch(s, si + 1, p, pi, cache);
            }
            else
            {
                res = si < s.Length && (pch == '?' || pch == s[si]) && IsMatch(s, si + 1, p, pi + 1, cache);
            }
            if (si < s.Length)
                cache[si, pi] = (byte)(res ? 1 : 2);
            return res;
        }
    }
}
