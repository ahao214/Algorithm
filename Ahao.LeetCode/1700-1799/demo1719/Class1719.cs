﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1719
{
    public class Class1719
    {
        public int CheckWays(int[][] pairs)
        {
            Dictionary<int, ISet<int>> adj = new Dictionary<int, ISet<int>>();
            foreach (int[] p in pairs)
            {
                if (!adj.ContainsKey(p[0]))
                {
                    adj.Add(p[0], new HashSet<int>());
                }
                if (!adj.ContainsKey(p[1]))
                {
                    adj.Add(p[1], new HashSet<int>());
                }
                adj[p[0]].Add(p[1]);
                adj[p[1]].Add(p[0]);
            }
            /* 检测是否存在根节点*/
            int root = -1;
            foreach (KeyValuePair<int, ISet<int>> pair in adj)
            {
                int node = pair.Key;
                ISet<int> neighbours = pair.Value;
                if (neighbours.Count == adj.Count - 1)
                {
                    root = node;
                }
            }
            if (root == -1)
            {
                return 0;
            }

            int res = 1;
            foreach (KeyValuePair<int, ISet<int>> pair in adj)
            {
                int node = pair.Key;
                ISet<int> neighbours = pair.Value;
                /* 如果当前节点为根节点 */
                if (node == root)
                {
                    continue;
                }
                int currDegree = neighbours.Count;
                int parent = -1;
                int parentDegree = int.MaxValue;

                /* 根据 degree 的大小找到 node 的父节点 parent */
                foreach (int neighbour in neighbours)
                {
                    if (adj[neighbour].Count < parentDegree && adj[neighbour].Count >= currDegree)
                    {
                        parent = neighbour;
                        parentDegree = adj[neighbour].Count;
                    }
                }
                if (parent == -1)
                {
                    return 0;
                }

                /* 检测父节点的集合是否包含所有的孩子节点 */
                foreach (int neighbour in neighbours)
                {
                    if (neighbour == parent)
                    {
                        continue;
                    }
                    if (!adj[parent].Contains(neighbour))
                    {
                        return 0;
                    }
                }
                if (parentDegree == currDegree)
                {
                    res = 2;
                }
            }
            return res;
        }
    }
}
