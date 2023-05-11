﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1016
{
    public class Class1016
    {

        public bool QueryString(string s, int n)
        {
            if (n == 1)
            {
                return s.IndexOf('1') != -1;
            }
            int k = 30;
            while ((1 << k) >= n)
            {
                --k;
            }
            if (s.Length < (1 << (k - 1)) + k - 1 || s.Length < n - (1 << k) + k + 1)
            {
                return false;
            }
            return Help(s, k, 1 << (k - 1), (1 << k) - 1) && Help(s, k + 1, 1 << k, n);
        }

        public bool Help(string s, int k, int mi, int ma)
        {
            ISet<int> set = new HashSet<int>();
            int t = 0;
            for (int r = 0; r < s.Length; ++r)
            {
                t = t * 2 + (s[r] - '0');
                if (r >= k)
                {
                    t -= (s[r - k] - '0') << k;
                }
                if (r >= k - 1 && t >= mi && t <= ma)
                {
                    set.Add(t);
                }
            }
            return set.Count == ma - mi + 1;
        }


    }
}
