﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1334
{
    public class Class1334
    {
        public int FindTheCity(int n, int[][] edges, int distanceThreshold)
        {
            int[] ans = { int.MaxValue / 2, -1 };
            int[][] mp = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                mp[i] = new int[n];
                Array.Fill(mp[i], int.MaxValue / 2);
            }
            foreach (int[] eg in edges)
            {
                int from = eg[0], to = eg[1], weight = eg[2];
                mp[from][to] = mp[to][from] = weight;
            }
            for (int k = 0; k < n; ++k)
            {
                mp[k][k] = 0;
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        mp[i][j] = Math.Min(mp[i][j], mp[i][k] + mp[k][j]);
                    }
                }
            }
            for (int i = 0; i < n; ++i)
            {
                int cnt = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (mp[i][j] <= distanceThreshold)
                    {
                        cnt++;
                    }
                }
                if (cnt <= ans[0])
                {
                    ans[0] = cnt;
                    ans[1] = i;
                }
            }
            return ans[1];
        }


    }
}
