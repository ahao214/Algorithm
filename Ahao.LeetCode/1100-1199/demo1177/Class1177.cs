﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1177
{
    public class Class1177
    {

        public IList<bool> CanMakePaliQueries(string s, int[][] queries)
        {
            int n = s.Length;
            int[] count = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                count[i + 1] = count[i] ^ (1 << (s[i] - 'a'));
            }
            List<Boolean> res = new List<Boolean>();
            for (int i = 0; i < queries.Length; i++)
            {
                int l = queries[i][0], r = queries[i][1], k = queries[i][2];
                int bits = 0, x = count[r + 1] ^ count[l];
                while (x > 0)
                {
                    x &= x - 1;
                    bits++;
                }
                res.Add(bits <= k * 2 + 1);
            }
            return res;
        }

    }
}
