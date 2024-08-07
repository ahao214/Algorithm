﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LeetCode.Medium.LC318
{
    /// <summary>
    /// 318. 最大单词长度乘积
    /// </summary>
    public class Class318
    {
        public int MaxProduct(string[] words)
        {
            int length = words.Length;
            int[] masks = new int[length];
            for (int i = 0; i < length; i++)
            {
                string word = words[i];
                int wordLength = word.Length;
                for (int j = 0; j < wordLength; j++)
                {
                    masks[i] |= 1 << (word[j] - 'a');
                }
            }
            int maxProd = 0;
            for (int i = 0; i < length; i++)
            {
                for (int j = i + 1; j < length; j++)
                {
                    if ((masks[i] & masks[j]) == 0)
                    {
                        maxProd = Math.Max(maxProd, words[i].Length * words[j].Length);
                    }
                }
            }
            return maxProd;
        }

        public int MaxProduc2(string[] words)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            int length = words.Length;
            for (int i = 0; i < length; i++)
            {
                int mask = 0;
                string word = words[i];
                int wordLength = word.Length;
                for (int j = 0; j < wordLength; j++)
                {
                    mask |= 1 << (word[j] - 'a');
                }

                if (dic.ContainsKey(mask))
                {
                    if (wordLength > dic[mask])
                    {
                        dic[mask] = wordLength;
                    }
                }
                else
                {
                    dic.Add(mask, wordLength);
                }
            }

            int maxProd = 0;
            foreach (int mask1 in dic.Keys)
            {
                int wordLength1 = dic[mask1];
                foreach (int mask2 in dic.Keys)
                {
                    if ((mask1 & mask2) == 0)
                    {
                        int wordLength2 = dic[mask2];
                        maxProd = Math.Max(maxProd, wordLength1 * wordLength2);
                    }
                }
            }
            return maxProd;
        }
    }
}
