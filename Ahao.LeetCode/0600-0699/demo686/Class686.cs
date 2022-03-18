using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo686
{
    /// <summary>
    /// 686. 重复叠加字符串匹配
    /// </summary>
    public class Class686
    {
        /// <summary>
        /// 方法一：Rabin-Karp 算法
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public int RepeatedStringMatch(string a, string b)
        {
            int an = a.Length, bn = b.Length;
            int index = StrStr(a, b);
            if (index == -1)
            {
                return -1;
            }
            if (an - index >= bn)
            {
                return 1;
            }
            return (bn + index - an - 1) / an + 2;
        }

        public int StrStr(string haystack, string needle)
        {
            int n = haystack.Length, m = needle.Length;
            if (m == 0)
            {
                return 0;
            }

            int k1 = 1000000009;
            int k2 = 1337;
            Random random = new Random();
            int kMod1 = random.Next(k1, k1 * 2);
            int kMod2 = random.Next(k2, k2 * 2);

            long hashNeedle = 0;
            for (int i = 0; i < m; i++)
            {
                char c = needle[i];
                hashNeedle = (hashNeedle * kMod2 + c) % kMod1;
            }
            long hashHaystack = 0, extra = 1;
            for (int i = 0; i < m - 1; i++)
            {
                hashHaystack = (hashHaystack * kMod2 + haystack[i % n]) % kMod1;
                extra = (extra * kMod2) % kMod1;
            }
            for (int i = m - 1; (i - m + 1) < n; i++)
            {
                hashHaystack = (hashHaystack * kMod2 + haystack[i % n]) % kMod1;
                if (hashHaystack == hashNeedle)
                {
                    return i - m + 1;
                }
                hashHaystack = (hashHaystack - extra * haystack[(i - m + 1) % n]) % kMod1;
                hashHaystack = (hashHaystack + kMod1) % kMod1;
            }
            return -1;
        }


        /// <summary>
        /// 方法二：Knuth-Morris-Pratt 算法
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public int RepeatedStringMatch2(string a, string b)
        {
            int an = a.Length, bn = b.Length;
            int index = StrStr2(a, b);
            if (index == -1)
            {
                return -1;
            }
            if (an - index >= bn)
            {
                return 1;
            }
            return (bn + index - an - 1) / an + 2;
        }

        public int StrStr2(string haystack, string needle)
        {
            int n = haystack.Length, m = needle.Length;
            if (m == 0)
            {
                return 0;
            }
            int[] pi = new int[m];
            for (int i = 1, j = 0; i < m; i++)
            {
                while (j > 0 && needle[i] != needle[j])
                {
                    j = pi[j - 1];
                }
                if (needle[i] == needle[j])
                {
                    j++;
                }
                pi[i] = j;
            }
            for (int i = 0, j = 0; i - j < n; i++)
            { // b 开始匹配的位置是否超过第一个叠加的 a
                while (j > 0 && haystack[i % n] != needle[j])
                { // haystack 是循环叠加的字符串，所以取 i % n
                    j = pi[j - 1];
                }
                if (haystack[i % n] == needle[j])
                {
                    j++;
                }
                if (j == m)
                {
                    return i - m + 1;
                }
            }
            return -1;
        }


        public int RepeatedStringMatch3(string a, string b)
        {
            if (a.Length >= b.Length)
            {
                if (a.Contains(b)) return 1;
                a += a;
                return a.Contains(b) ? 2 : -1;
            }
            //将b按照a分割
            string[] s = b.Split(new string[] { a }, StringSplitOptions.None);
            if (s.Length == 1) //b不包含a时无法分割，结果就是b本身
            {
                a += a;
                return a.Contains(b) ? 2 : -1;
            }
            if (!a.EndsWith(s[0]) || !a.StartsWith(s[s.Length - 1]))
            {
                return -1;
            }
            for (int i = 1; i < s.Length - 1; i++)
            {
                if (s[i] != "") return -1;//分割后除了头尾都必是空字符
            }
            int ans = s.Length + 1;
            if (s[0] == "") ans--; //特殊情况，b以a为开头
            if (s[s.Length - 1] == "") ans--; //特殊情况，b以a为结尾
            return ans;
        }
    }
}
