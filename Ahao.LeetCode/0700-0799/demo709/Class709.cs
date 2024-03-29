﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo709
{
    /// <summary>
    /// 709. 转换成小写字母
    /// </summary>
    public class Class709
    {
        public string ToLowerCase(string s)
        {
            if (string.IsNullOrEmpty(s))
            {
                return string.Empty;
            }
            string newS = string.Empty;
            foreach (char c in s)
            {
                newS += c.ToString().ToLower();
            }
            return newS;
        }

        public string ToLowerCase2(string s)
        {
            StringBuilder sb = new StringBuilder();
            foreach (char ch in s)
            {
                char chNew = (int)ch >= 65 && (int)ch <= 90 ? (char)(ch | 32) : (char)ch;
                sb.Append(chNew);
            }
            return sb.ToString();
        }
    }
}
