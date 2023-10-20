﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2316
{
    public class Class2316
    {

        public long CountPairs(int n, int[][] edges)
        {
            UnionFind uf = new UnionFind(n);
            foreach (int[] edge in edges)
            {
                int x = edge[0], y = edge[1];
                uf.Union(x, y);
            }
            long res = 0;
            for (int i = 0; i < n; i++)
            {
                res += n - uf.GetSize(uf.Find(i));
            }
            return res / 2;
        }


        class UnionFind
        {
            int[] parents;
            int[] sizes;

            public UnionFind(int n)
            {
                parents = new int[n];
                for (int i = 0; i < n; i++)
                {
                    parents[i] = i;
                }
                sizes = new int[n];
                Array.Fill(sizes, 1);
            }

            public int Find(int x)
            {
                if (parents[x] == x)
                {
                    return x;
                }
                else
                {
                    parents[x] = Find(parents[x]);
                    return parents[x];
                }
            }

            public void Union(int x, int y)
            {
                int rx = Find(x), ry = Find(y);
                if (rx != ry)
                {
                    if (sizes[rx] > sizes[ry])
                    {
                        parents[ry] = rx;
                        sizes[rx] += sizes[ry];
                    }
                    else
                    {
                        parents[rx] = ry;
                        sizes[ry] += sizes[rx];
                    }
                }
            }

            public int GetSize(int x)
            {
                return sizes[x];
            }

        }
    }
}
