﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2734
{
    public class Class2734
    {
        public string SmallestString(string s)
        {
            int indexOfFirstNonA = FindFirstNonA(s);
            if (indexOfFirstNonA == s.Length)
            {
                StringBuilder sb = new StringBuilder(s);
                sb[s.Length - 1] = 'z';
                return sb.ToString();
            }
            int indexOfFirstA_AfterFirstNonA = FindFirstA_AfterFirstNonA(s, indexOfFirstNonA);
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < s.Length; i++)
            {
                char c = s[i];
                if (i >= indexOfFirstNonA && i < indexOfFirstA_AfterFirstNonA)
                {
                    res.Append((char)(c - 1));
                }
                else
                {
                    res.Append(c);
                }
            }
            return res.ToString();
        }

        public int FindFirstNonA(string s)
        {
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] != 'a')
                    return i;
            }
            return s.Length;
        }

        public int FindFirstA_AfterFirstNonA(string s, int firstNonA)
        {
            for (int i = firstNonA; i < s.Length; i++)
            {
                if (s[i] == 'a')
                {
                    return i;
                }
            }
            return s.Length;
        }

    }
}
