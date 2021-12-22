﻿using System;
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

    }
}
