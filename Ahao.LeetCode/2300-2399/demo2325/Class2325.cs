﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2325
{
    public class Class2325
    {

        public string DecodeMessage(string key, string message)
        {
            char cur = 'a';
            IDictionary<char, char> rules = new Dictionary<char, char>();

            foreach (char c in key)
            {
                if (c != ' ' && !rules.ContainsKey(c))
                {
                    rules.Add(c, cur);
                    ++cur;
                }
            }

            StringBuilder sb = new StringBuilder();
            foreach (char c in message)
            {
                if (c != ' ')
                {
                    sb.Append(rules[c]);
                }
                else
                {
                    sb.Append(c);
                }
            }

            return sb.ToString();
        }

    }
}
