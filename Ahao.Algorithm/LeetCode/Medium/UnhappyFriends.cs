﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1583. 统计不开心的朋友
    /// </summary>
    public class UnhappyFriends
    {
        public int Method(int n, int[][] preferences, int[][] pairs)
        {
            int[,] order = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    order[i, preferences[i][j]] = j;
                }
            }
            int[] match = new int[n];
            foreach (int[] pair in pairs)
            {
                int person0 = pair[0], person1 = pair[1];
                match[person0] = person1;
                match[person1] = person0;
            }
            int unhappyCount = 0;
            for (int x = 0; x < n; x++)
            {
                int y = match[x];
                int index = order[x, y];
                for (int i = 0; i < index; i++)
                {
                    int u = preferences[x][i];
                    int v = match[u];
                    if (order[u, x] < order[u, v])
                    {
                        unhappyCount++;
                        break;
                    }
                }
            }
            return unhappyCount;
        }
    }
}
