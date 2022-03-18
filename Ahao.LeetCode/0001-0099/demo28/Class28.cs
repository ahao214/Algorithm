using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo28
{
    /*
     28. 实现 strStr()
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1
     */
    public class Class28
    {
        public int StrStr(string haystack, string needle)
        {
            if (string.IsNullOrEmpty(needle))
                return 0;
            if (string.IsNullOrEmpty(haystack))
                return -1;
            return sandy(haystack, needle);
        }

        private int sandy(string s, string p)
        {
            var shift = new Dictionary<char, int>(p.Length);
            for (int i = 0; i < p.Length; i++)
            {
                shift[p[i]] = p.Length - i;
            }
            var left = 0;
            while (left <= s.Length - p.Length)
            {
                var matched = true;
                for (int j = 0; j < p.Length; j++)
                {
                    if (s[left + j] != p[j])
                    {
                        matched = false;
                        break;
                    }
                }
                if (matched)
                    return left;
                if (left + p.Length < s.Length && shift.TryGetValue(s[left + p.Length], out var n))
                {
                    left += n;
                }
                else
                {
                    left += p.Length + 1;
                }
            }
            return -1;
        }
    }
}
