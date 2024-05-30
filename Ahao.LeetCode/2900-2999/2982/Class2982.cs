﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2900_2999._2982
{
    internal class Class2982
    {
        public int MaximumLength(string s)
        {
            int n = s.Length;
            IDictionary<char, IList<int>> cnt = new Dictionary<char, IList<int>>();

            for (int i = 0, j = 0; i < n; i = j)
            {
                while (j < n && s[j] == s[i])
                {
                    j++;
                }
                cnt.TryAdd(s[i], new List<int>());
                cnt[s[i]].Add(j - i);
            }

            int res = -1;
            foreach (IList<int> vec in cnt.Values)
            {
                int lo = 1, hi = n - 2;
                while (lo <= hi)
                {
                    int mid = (lo + hi) >> 1;
                    int count = 0;
                    foreach (int x in vec)
                    {
                        if (x >= mid)
                        {
                            count += x - mid + 1;
                        }
                    }
                    if (count >= 3)
                    {
                        res = Math.Max(res, mid);
                        lo = mid + 1;
                    }
                    else
                    {
                        hi = mid - 1;
                    }
                }
            }
            return res;
        }


    }
}
