using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo97
{
    /// <summary>
    /// 97. 交错字符串
    /// </summary>
    public class Class97
    {
        public bool IsInterleave(string s1, string s2, string s3)
        {
            if (s1 == null || s2 == null || s3 == null)
            {
                return false;
            }

            if (s1.Length + s2.Length != s3.Length)
            {
                return false;
            }

            if (!IsSameChars(s1 + s2, s3))
                return false;
            var cache = new Dictionary<(int i1, int i2), bool>();
            return IsInterleave(s1, 0, s2, 0, s3, 0, cache);
        }

        private bool IsInterleave(string s1, int i1, string s2, int i2, string t, int it, Dictionary<(int i1, int i2), bool> cache)
        {
            if (cache.TryGetValue((i1, i2), out var result))
                return result;
            if (i1 == s1.Length)
            {
                result = string.CompareOrdinal(s2, i2, t, it, t.Length - it) == 0;
            }
            else if (i2 == s2.Length)
            {
                result = string.CompareOrdinal(s1, i1, t, it, t.Length - it) == 0;
            }
            else
            {
                result = t[it] == s1[i1] && IsInterleave(s1, i1 + 1, s2, i2, t, it + 1, cache) ||
                    t[it] == s2[i2] && IsInterleave(s1, i1, s2, i2 + 1, t, it + 1, cache);
            }
            cache.Add((i1, i2), result);
            return result;
        }

        private bool IsSameChars(string s1, string s2)
        {
            if (s1.Length != s2.Length)
            {
                return false;
            }

            var set1 = new Dictionary<char, int>(s1.Length);
            var set2 = new Dictionary<char, int>(s2.Length);
            for (int i = 0; i < s1.Length; i++)
            {
                var ch1 = s1[i];
                var ch2 = s2[i];
                if (ch1 == ch2)
                    continue;
                if (TryRemove(set2, ch1) || TryRemove(set1, ch2))
                {
                    continue;
                }
                set1.Add(ch1, 1);
                set2.Add(ch2, 1);
            }
            return set1.Count == 0 && set2.Count == 0;

            bool TryRemove(Dictionary<char, int> set, char ch)
            {
                if (!set.TryGetValue(ch, out var count))
                {
                    return false;
                }
                if (count == 1)
                    set.Remove(ch);
                else
                    set[ch] = count - 1;
                return true;
            }
        }
    }
}
