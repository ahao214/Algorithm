﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1129
{
    public class Class1129
    {
        public int[] ShortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges)
        {
            IList<int>[][] next = new IList<int>[2][];
            for (int i = 0; i < 2; i++)
            {
                next[i] = new IList<int>[n];
                for (int j = 0; j < n; j++)
                {
                    next[i][j] = new List<int>();
                }
            }
            foreach (int[] edge in redEdges)
            {
                next[0][edge[0]].Add(edge[1]);
            }
            foreach (int[] edge in blueEdges)
            {
                next[1][edge[0]].Add(edge[1]);
            }
            int[][] dist = new int[2][]; // 两种类型的颜色最短路径的长度
            for (int i = 0; i < 2; i++)
            {
                dist[i] = new int[n];
                Array.Fill(dist[i], int.MaxValue);
            }
            Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
            dist[0][0] = 0;
            dist[1][0] = 0;
            queue.Enqueue(new Tuple<int, int>(0, 0));
            queue.Enqueue(new Tuple<int, int>(0, 1));
            while (queue.Count > 0)
            {
                Tuple<int, int> pair = queue.Dequeue();
                int x = pair.Item1, t = pair.Item2;
                foreach (int y in next[1 - t][x])
                {
                    if (dist[1 - t][y] != int.MaxValue)
                    {
                        continue;
                    }
                    dist[1 - t][y] = dist[t][x] + 1;
                    queue.Enqueue(new Tuple<int, int>(y, 1 - t));
                }
            }
            int[] answer = new int[n];
            for (int i = 0; i < n; i++)
            {
                answer[i] = Math.Min(dist[0][i], dist[1][i]);
                if (answer[i] == int.MaxValue)
                {
                    answer[i] = -1;
                }
            }
            return answer;
        }

    }
}
