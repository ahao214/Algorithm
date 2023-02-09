using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5
{
    public class Class5
    {
        public string LongestPalindrome(string s)
        {
            if (s == null)
            {
                return string.Empty;
            }
            ReadOnlySpan<char> span = s.ToCharArray();
            return longest(span);
        }

        public string longest(in ReadOnlySpan<char> span)
        {
            if (span.Length == 0)
            {
                return string.Empty;
            }

            var j = span.Length / 2;
            var i = span.Length % 2 == 0 ? j - 1 : j;
            var res = span.Slice(0, 1);
            while (res.Length < (i + 1) * 2)
            {
                var pli = longestABBA(span, i);
                if (pli.Length > res.Length)
                {
                    res = pli;
                }

                pli = longestABXBA(span, i);
                if (pli.Length > res.Length)
                {
                    res = pli;
                }

                pli = longestABBA(span, j);
                if (pli.Length > res.Length)
                {
                    res = pli;
                }

                pli = longestABXBA(span, j);
                if (pli.Length > res.Length)
                {
                    res = pli;
                }
                i--;
                j++;
            }
            return res.ToString();
        }

        private ReadOnlySpan<char> longestABBA(in ReadOnlySpan<char> span, int i)
        {
            var p = i;
            var q = p + 1;
            var len = 0;
            while (p >= 0 && q < span.Length && span[p] == span[q])
            {
                p--;
                q++;
                len += 2;
            }
            return p < span.Length ? span.Slice(p + 1, len) : span.Slice(0, 0);
        }

        private ReadOnlySpan<char> longestABXBA(in ReadOnlySpan<char> span, int i)
        {
            var p = i - 1;
            var q = i + 1;
            var len = 1;
            while (p >= 0 && q < span.Length && span[p] == span[q])
            {
                p--;
                q++;
                len += 2;
            }
            return span.Slice(p + 1, len);
        }
    }
}
