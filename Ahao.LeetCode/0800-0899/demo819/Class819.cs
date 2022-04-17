﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo819
{
    public class Class819
    {
        public string MostCommonWord(string paragraph, string[] banned)
        {
            ISet<string> bannedSet = new HashSet<string>();
            foreach (string word in banned)
            {
                bannedSet.Add(word);
            }
            int maxFrequency = 0;
            Dictionary<string, int> frequencies = new Dictionary<string, int>();
            StringBuilder sb = new StringBuilder();
            int length = paragraph.Length;
            for (int i = 0; i <= length; i++)
            {
                if (i < length && char.IsLetter(paragraph[i]))
                    sb.Append(char.ToLower(paragraph[i]));
                else if (sb.Length > 0)
                {
                    string word = sb.ToString();
                    if (!bannedSet.Contains(word))
                    {
                        if (!frequencies.ContainsKey(word))
                            frequencies.Add(word, 1);
                        else
                            frequencies[word]++;
                        maxFrequency = Math.Max(maxFrequency, frequencies[word]);
                    }
                    sb.Length = 0;
                }
            }
            string mostCommon = "";
            foreach (KeyValuePair<string, int> pair in frequencies)
            {
                string word = pair.Key;
                int frequency = pair.Value;
                if (frequency == maxFrequency)
                {
                    mostCommon = word;
                    break;
                }
            }
            return mostCommon;
        }
    }


}
