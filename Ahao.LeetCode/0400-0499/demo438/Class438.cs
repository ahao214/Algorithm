﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.LC438
{
    public class Class438
    {
        public IList<int> FindAnagrams(string s, string p)
        {
            List<int> res = new List<int>();
            int pLen = p.Length;
            int sLen = s.Length;
            if (pLen > sLen)
            {
                return res;
            }

            int[] count = new int[26];
            int diff = 0;
            for (int i = 0; i < p.Length; i++)
            {
                count[p[i] - 'a']--;
                if (count[p[i] - 'a'] == -1)
                    diff++;
            }

            for (int i = 0; i < p.Length; i++)//初始化滑动窗口
            {
                if (count[s[i] - 'a'] == 0)
                    diff++;
                count[s[i] - 'a']++;
                if (count[s[i] - 'a'] == 0)
                    diff--;
            }

            if (diff == 0)
                res.Add(0);

            for (int i = pLen; i < sLen; i++)//滑动窗口遍历
            {
                if (count[s[i] - 'a'] == 0)
                    diff++;
                count[s[i] - 'a']++;
                if (count[s[i] - 'a'] == 0)
                    diff--;
                if (count[s[i - pLen] - 'a'] == 0)
                    diff++;
                count[s[i - pLen] - 'a']--;
                if (count[s[i - pLen] - 'a'] == 0)
                    diff--;
                if (diff == 0)
                    res.Add(i - pLen + 1);
            }

            return res;
        }

        public IList<int> FindAnagrams2(string s, string p)
        {
            int sLen = s.Length;
            int pLen = p.Length;
            if (sLen < pLen)
            {
                return new List<int>();
            }

            IList<int> res = new List<int>();
            int[] sCount = new int[26];
            int[] pCount = new int[26];
            for (int i = 0; i < pLen; i++)
            {
                ++sCount[s[i] - 'a'];
                ++pCount[p[i] - 'a'];
            }


            if (Enumerable.SequenceEqual(sCount, pCount))
            {
                res.Add(0);
            }

            for (int i = 0; i < sLen - pLen; i++)
            {
                --sCount[s[i] - 'a'];
                ++sCount[s[i + pLen] - 'a'];

                if (Enumerable.SequenceEqual(sCount, pCount))
                {
                    res.Add(i + 1);
                }
            }
            return res;
        }
    }
}
