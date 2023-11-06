﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo318
{
    public class Class318
    {

        public int MaxProduct(string[] words)
        {
            int length = words.Length;
            int[] masks = new int[length];
            for (int i = 0; i < length; i++)
            {
                String word = words[i];
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



    }
}
