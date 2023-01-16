﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1813
{
    public class Class1813
    {
        public bool AreSentencesSimilar(string sentence1, string sentence2)
        {
            string[] words1 = sentence1.Split(new char[] { ' ' });
            string[] words2 = sentence2.Split(new char[] { ' ' });
            int i = 0, j = 0;
            while (i < words1.Length && i < words2.Length && words1[i].Equals(words2[i]))
            {
                i++;
            }
            while (j < words1.Length - i && j < words2.Length - i && words1[words1.Length - j - 1].Equals(words2[words2.Length - j - 1]))
            {
                j++;
            }
            return i + j == Math.Min(words1.Length, words2.Length);
        }

    }
}
