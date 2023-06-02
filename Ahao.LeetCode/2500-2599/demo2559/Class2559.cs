﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2559
{
    public class Class2559
    {

        public int[] VowelStrings(string[] words, int[][] queries)
        {
            int n = words.Length;
            int[] prefixSums = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                int value = IsVowelString(words[i]) ? 1 : 0;
                prefixSums[i + 1] = prefixSums[i] + value;
            }
            int q = queries.Length;
            int[] ans = new int[q];
            for (int i = 0; i < q; i++)
            {
                int start = queries[i][0], end = queries[i][1];
                ans[i] = prefixSums[end + 1] - prefixSums[start];
            }
            return ans;
        }

        public bool IsVowelString(string word)
        {
            return IsVowelLetter(word[0]) && IsVowelLetter(word[word.Length - 1]);
        }

        public bool IsVowelLetter(char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }


    }
}
