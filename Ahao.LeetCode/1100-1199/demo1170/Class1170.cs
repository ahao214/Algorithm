﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1170
{
    public class Class1170
    {

        public int[] NumSmallerByFrequency(string[] queries, string[] words)
        {
            int[] count = new int[12];
            foreach (string s in words)
            {
                count[F(s)]++;
            }
            for (int i = 9; i >= 1; i--)
            {
                count[i] += count[i + 1];
            }
            int[] res = new int[queries.Length];
            for (int i = 0; i < queries.Length; i++)
            {
                string s = queries[i];
                res[i] = count[F(s) + 1];
            }
            return res;
        }

        public int F(string s)
        {
            int cnt = 0;
            char ch = 'z';
            foreach (char c in s)
            {
                if (c < ch)
                {
                    ch = c;
                    cnt = 1;
                }
                else if (c == ch)
                {
                    cnt++;
                }
            }
            return cnt;
        }


    }
}
