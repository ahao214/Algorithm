﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1816
{
    public class Class1816
    {
        public string TruncateSentence(string s, int k)
        {
            var str = s.Split(' ').Skip(0).Take(k).ToArray();
            return string.Join(' ', str);
        }


        public string TruncateSentence2(string s, int k)
        {
            int n = s.Length;
            int end = 0;
            int count = 0;
            for (int i = 1; i <= n; i++)
            {
                if (i == n || s[i] == ' ')
                {
                    count++;
                    if (count == k)
                    {
                        end = i;
                        break;
                    }
                }
            }
            return s.Substring(0, end);
        }
    }
}
