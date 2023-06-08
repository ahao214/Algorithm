﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2699
{
    public class Class2699
    {

        public int[][] ModifiedGraphEdges(int n, int[][] edges, int source, int destination, int target)
        {
            int k = 0;
            foreach (int[] e in edges)
            {
                if (e[2] == -1)
                {
                    ++k;
                }
            }

            if (Dijkstra(source, destination, Construct(n, edges, 0, target)) > target)
            {
                return new int[0][];
            }
            if (Dijkstra(source, destination, Construct(n, edges, (long)k * (target - 1), target)) < target)
            {
                return new int[0][];
            }

            long left = 0, right = (long)k * (target - 1), ans = 0;
            while (left <= right)
            {
                long mid = (left + right) / 2;
                if (Dijkstra(source, destination, Construct(n, edges, mid, target)) >= target)
                {
                    ans = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            foreach (int[] e in edges)
            {
                if (e[2] == -1)
                {
                    if (ans >= target - 1)
                    {
                        e[2] = target;
                        ans -= target - 1;
                    }
                    else
                    {
                        e[2] = (int)(1 + ans);
                        ans = 0;
                    }
                }
            }

            return edges;
        }

        public long Dijkstra(int source, int destination, int[][] adjMatrix)
        {
            // 朴素的 dijkstra 算法
            // adjMatrix 是一个邻接矩阵
            int n = adjMatrix.Length;
            long[] dist = new long[n];
            Array.Fill(dist, int.MaxValue / 2);
            bool[] used = new bool[n];
            dist[source] = 0;

            for (int round = 0; round < n - 1; ++round)
            {
                int u = -1;
                for (int i = 0; i < n; ++i)
                {
                    if (!used[i] && (u == -1 || dist[i] < dist[u]))
                    {
                        u = i;
                    }
                }
                used[u] = true;
                for (int v = 0; v < n; ++v)
                {
                    if (!used[v] && adjMatrix[u][v] != -1)
                    {
                        dist[v] = Math.Min(dist[v], dist[u] + adjMatrix[u][v]);
                    }
                }
            }

            return dist[destination];
        }

        public int[][] Construct(int n, int[][] edges, long idx, int target)
        {
            // 需要构造出第 idx 种不同的边权情况，返回一个邻接矩阵
            int[][] adjMatrix = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                adjMatrix[i] = new int[n];
                Array.Fill(adjMatrix[i], -1);
            }
            foreach (int[] e in edges)
            {
                int u = e[0], v = e[1], w = e[2];
                if (w != -1)
                {
                    adjMatrix[u][v] = adjMatrix[v][u] = w;
                }
                else
                {
                    if (idx >= target - 1)
                    {
                        adjMatrix[u][v] = adjMatrix[v][u] = target;
                        idx -= (target - 1);
                    }
                    else
                    {
                        adjMatrix[u][v] = adjMatrix[v][u] = (int)(1 + idx);
                        idx = 0;
                    }
                }
            }
            return adjMatrix;
        }


    }
}
