﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1807
{
    public class Class1807
    {
        public string Evaluate(string s, IList<IList<string>> knowledge)
        {
            IDictionary<string, string> dict = new Dictionary<string, string>();
            foreach (IList<string> kd in knowledge)
            {
                dict.Add(kd[0], kd[1]);
            }
            bool addKey = false;
            StringBuilder key = new StringBuilder();
            StringBuilder res = new StringBuilder();
            foreach (char c in s)
            {
                if (c == '(')
                {
                    addKey = true;
                }
                else if (c == ')')
                {
                    if (dict.ContainsKey(key.ToString()))
                    {
                        res.Append(dict[key.ToString()]);
                    }
                    else
                    {
                        res.Append('?');
                    }
                    addKey = false;
                    key.Length = 0;
                }
                else
                {
                    if (addKey)
                    {
                        key.Append(c);
                    }
                    else
                    {
                        res.Append(c);
                    }
                }
            }
            return res.ToString();
        }
    }
}
