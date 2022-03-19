using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1763
{
    /*
     1763. 最长的美好子字符串
     当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，就称这个字符串 s 是 美好 字符串。比方说，"abABB" 是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。

    给你一个字符串 s ，请你返回 s 最长的 美好子字符串 。如果有多个答案，请你返回 最早 出现的一个。如果不存在美好子字符串，请你返回一个空字符串。
     */
    public class Class1763
    {
        /// <summary>
        /// 方法一：枚举
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public string LongestNiceSubstring(string s)
        {
            int n = s.Length;
            if (string.IsNullOrEmpty(s) || n == 1)
            {
                return "";
            }

            int maxPos = 0;
            int maxLen = 0;
            for (int i = 0; i < n; i++)
            {
                int lower = 0;
                int upper = 0;
                for (int j = i; j < n; ++j)
                {
                    if (char.IsLower(s[j]))
                    {
                        lower |= 1 << (s[j] - 'a');
                    }
                    else
                    {
                        upper |= 1 << (s[j] - 'A');
                    }
                    if (lower == upper && j - i + 1 > maxLen)
                    {
                        maxPos = i;
                        maxLen = j - i + 1;
                    }

                }
            }
            return s.Substring(maxPos, maxLen);
        }


        #region 方法二：分冶
        private int maxPos;
        private int maxLen;

        public string LongestNiceSubstring1(string s)
        {
            this.maxPos = 0;
            this.maxLen = 0;
            DFS(s, 0, s.Length - 1);
            return s.Substring(maxPos, maxLen);
        }

        public void DFS(String s, int start, int end)
        {
            if (start >= end)
            {
                return;
            }
            int lower = 0, upper = 0;
            for (int i = start; i <= end; ++i)
            {
                if (char.IsLower(s[i]))
                {
                    lower |= 1 << (s[i] - 'a');
                }
                else
                {
                    upper |= 1 << (s[i] - 'A');
                }
            }
            if (lower == upper)
            {
                if (end - start + 1 > maxLen)
                {
                    maxPos = start;
                    maxLen = end - start + 1;
                }
                return;
            }
            int valid = lower & upper;
            int pos = start;
            while (pos <= end)
            {
                start = pos;
                while (pos <= end && (valid & (1 << char.ToLower(s[pos]) - 'a')) != 0)
                {
                    ++pos;
                }
                DFS(s, start, pos - 1);
                ++pos;
            }
        }

        #endregion


        #region 滑动窗口

        public string LongestNiceSubstring2(string s)
        {
            this.maxPos = 0;
            this.maxLen = 0;

            int types = 0;
            for (int i = 0; i < s.Length; ++i)
            {
                types |= 1 << (char.ToLower(s[i]) - 'a');
            }
            types = Count((uint)types);
            for (int i = 1; i <= types; ++i)
            {
                Check(s, i);
            }
            return s.Substring(maxPos, maxLen);
        }

        public void Check(string s, int typeNum)
        {
            int[] lowerCnt = new int[26];
            int[] upperCnt = new int[26];
            int cnt = 0;
            for (int l = 0, r = 0, total = 0; r < s.Length; ++r)
            {
                int idx = char.ToLower(s[r]) - 'a';
                if (char.IsLower(s[r]))
                {
                    ++lowerCnt[idx];
                    if (lowerCnt[idx] == 1 && upperCnt[idx] > 0)
                    {
                        ++cnt;
                    }
                }
                else
                {
                    ++upperCnt[idx];
                    if (upperCnt[idx] == 1 && lowerCnt[idx] > 0)
                    {
                        ++cnt;
                    }
                }
                total += (lowerCnt[idx] + upperCnt[idx]) == 1 ? 1 : 0;

                while (total > typeNum)
                {
                    idx = char.ToLower(s[l]) - 'a';
                    total -= (lowerCnt[idx] + upperCnt[idx]) == 1 ? 1 : 0;
                    if (char.IsLower(s[l]))
                    {
                        --lowerCnt[idx];
                        if (lowerCnt[idx] == 0 && upperCnt[idx] > 0)
                        {
                            --cnt;
                        }
                    }
                    else
                    {
                        --upperCnt[idx];
                        if (upperCnt[idx] == 0 && lowerCnt[idx] > 0)
                        {
                            --cnt;
                        }
                    }
                    ++l;
                }
                if (cnt == typeNum && r - l + 1 > maxLen)
                {
                    maxPos = l;
                    maxLen = r - l + 1;
                }
            }
        }

        public static int Count(uint x)
        {
            x = x - ((x >> 1) & 0x55555555);
            x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
            x = (x + (x >> 4)) & 0x0f0f0f0f;
            x = x + (x >> 8);
            x = x + (x >> 16);
            return (int)x & 0x3f;
        }


        #endregion 

    }
}
