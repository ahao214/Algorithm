﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo824
{
    public class Class824
    {
        public string ToGoatLatin(string sentence)
        {
            ISet<char> vowels = new HashSet<char>();
            vowels.Add('a');
            vowels.Add('e');
            vowels.Add('i');
            vowels.Add('o');
            vowels.Add('u');
            vowels.Add('A');
            vowels.Add('E');
            vowels.Add('I');
            vowels.Add('O');
            vowels.Add('U');

            int n = sentence.Length;
            int i = 0, cnt = 1;
            StringBuilder ans = new StringBuilder();

            while (i < n)
            {
                int j = i;
                while (j < n && sentence[j] != ' ')
                {
                    ++j;
                }

                ++cnt;
                if (cnt != 2)
                {
                    ans.Append(' ');
                }
                if (vowels.Contains(sentence[i]))
                {
                    ans.Append(sentence.Substring(i, j - i));
                }
                else
                {
                    ans.Append(sentence.Substring(i + 1, j - i - 1));
                    ans.Append(sentence[i]);
                }
                ans.Append('m');
                for (int k = 0; k < cnt; ++k)
                {
                    ans.Append('a');
                }

                i = j + 1;
            }

            return ans.ToString();
        }

    }
}
