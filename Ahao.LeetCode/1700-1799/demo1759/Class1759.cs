﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1759
{
    public class Class1759
    {
        public int CountHomogenous(string s)
        {
            const int MOD = 1000000007;
            long res = 0;
            char prev = s[0];
            int cnt = 0;
            foreach (char c in s)
            {
                if (c == prev)
                {
                    cnt++;
                }
                else
                {
                    res += (long)(cnt + 1) * cnt / 2;
                    cnt = 1;
                    prev = c;
                }
            }
            res += (long)(cnt + 1) * cnt / 2;
            return (int)(res % MOD);
        }
    }
}
