﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo753
{
    public class Class753
    {

        ISet<int> seen = new HashSet<int>();
        StringBuilder ans = new StringBuilder();
        int highest;
        int k;

        public string CrackSafe(int n, int k)
        {
            highest = (int)Math.Pow(10, n - 1);
            this.k = k;
            DFS(0);
            for (int i = 1; i < n; i++)
            {
                ans.Append('0');
            }
            return ans.ToString();
        }

        public void DFS(int node)
        {
            for (int x = 0; x < k; ++x)
            {
                int nei = node * 10 + x;
                if (!seen.Contains(nei))
                {
                    seen.Add(nei);
                    DFS(nei % highest);
                    ans.Append(x);
                }
            }
        }
    }
}
