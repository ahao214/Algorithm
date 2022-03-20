﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2000_2099.demo2039
{
    public class Class2039
    {
        /// <summary>
        /// 广度优先
        /// </summary>
        /// <param name="edges"></param>
        /// <param name="patience"></param>
        /// <returns></returns>
        public int NetworkBecomesIdle(int[][] edges, int[] patience)
        {
            int n = patience.Length;
            IList<int>[] adj = new IList<int>[n];
            for (int i = 0; i < n; ++i)
            {
                adj[i] = new List<int>();
            }
            bool[] visit = new bool[n];
            foreach (int[] v in edges)
            {
                adj[v[0]].Add(v[1]);
                adj[v[1]].Add(v[0]);
            }

            Queue<int> queue = new Queue<int>();
            queue.Enqueue(0);
            visit[0] = true;
            int dist = 1;
            int ans = 0;
            while (queue.Count > 0)
            {
                int size = queue.Count;
                for (int i = 0; i < size; i++)
                {
                    int curr = queue.Dequeue();
                    foreach (int v in adj[curr])
                    {
                        if (visit[v])
                        {
                            continue;
                        }
                        queue.Enqueue(v);
                        int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                        ans = Math.Max(ans, time);
                        visit[v] = true;
                    }
                }
                dist++;
            }
            return ans;
        }

    }
}
