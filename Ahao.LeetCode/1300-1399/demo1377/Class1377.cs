﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1377
{
    public class Class1377
    {

        public double FrogPosition(int n, int[][] edges, int t, int target)
        {
            List<List<int>> g = new List<List<int>>();
            for (int i = 0; i <= n; i++)
            {
                g.Add(new List<int>());
            }
            for (int i = 0; i < edges.Length; i++)
            {
                g[edges[i][0]].Add(edges[i][1]);
                g[edges[i][1]].Add(edges[i][0]);
            }
            bool[] seen = new bool[n + 1];
            return Dfs(g, seen, 1, t, target);
        }

        private double Dfs(List<List<int>> g, bool[] seen, int i, int t, int target)
        {
            int nxt = i == 1 ? g[i].Count : g[i].Count - 1;
            if (t == 0 || nxt == 0)
            {
                return i == target ? 1.0 : 0.0;
            }
            seen[i] = true;
            double ans = 0.0;
            foreach (int j in g[i])
            {
                if (!seen[j])
                {
                    ans += Dfs(g, seen, j, t - 1, target);
                }
            }
            return ans / nxt;
        }

    }
}
