﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1632
{
    public class Class1632
    {
        public int[][] MatrixRankTransform(int[][] matrix)
        {
            int m = matrix.Length, n = matrix[0].Length;
            UnionFind uf = new UnionFind(m, n);
            for (int i = 0; i < m; i++)
            {
                IDictionary<int, IList<int[]>> num2indexList = new Dictionary<int, IList<int[]>>();
                for (int j = 0; j < n; j++)
                {
                    int num = matrix[i][j];
                    num2indexList.TryAdd(num, new List<int[]>());
                    num2indexList[num].Add(new int[] { i, j });
                }
                foreach (IList<int[]> indexList in num2indexList.Values)
                {
                    int[] arr1 = indexList[0];
                    int i1 = arr1[0], j1 = arr1[1];
                    for (int k = 1; k < indexList.Count; k++)
                    {
                        int[] arr2 = indexList[k];
                        int i2 = arr2[0], j2 = arr2[1];
                        uf.Union(i1, j1, i2, j2);
                    }
                }
            }
            for (int j = 0; j < n; j++)
            {
                IDictionary<int, IList<int[]>> num2indexList = new Dictionary<int, IList<int[]>>();
                for (int i = 0; i < m; i++)
                {
                    int num = matrix[i][j];
                    num2indexList.TryAdd(num, new List<int[]>());
                    num2indexList[num].Add(new int[] { i, j });
                }
                foreach (IList<int[]> indexList in num2indexList.Values)
                {
                    int[] arr1 = indexList[0];
                    int i1 = arr1[0], j1 = arr1[1];
                    for (int k = 1; k < indexList.Count; k++)
                    {
                        int[] arr2 = indexList[k];
                        int i2 = arr2[0], j2 = arr2[1];
                        uf.Union(i1, j1, i2, j2);
                    }
                }
            }

            int[][] degree = new int[m][];
            for (int i = 0; i < m; i++)
            {
                degree[i] = new int[n];
            }
            IDictionary<int, IList<int[]>> adj = new Dictionary<int, IList<int[]>>();
            for (int i = 0; i < m; i++)
            {
                IDictionary<int, int[]> num2index = new Dictionary<int, int[]>();
                for (int j = 0; j < n; j++)
                {
                    int num = matrix[i][j];
                    if (!num2index.ContainsKey(num))
                    {
                        num2index.Add(num, new int[] { i, j });
                    }
                    else
                    {
                        num2index[num] = new int[] { i, j };
                    }
                }
                IList<int> sortedArray = new List<int>(num2index.Keys);
                ((List<int>)sortedArray).Sort();
                for (int k = 1; k < sortedArray.Count; k++)
                {
                    int[] prev = num2index[sortedArray[k - 1]];
                    int[] curr = num2index[sortedArray[k]];
                    int i1 = prev[0], j1 = prev[1], i2 = curr[0], j2 = curr[1];
                    int[] root1 = uf.Find(i1, j1);
                    int[] root2 = uf.Find(i2, j2);
                    int ri1 = root1[0], rj1 = root1[1], ri2 = root2[0], rj2 = root2[1];
                    degree[ri2][rj2]++;
                    adj.TryAdd(ri1 * n + rj1, new List<int[]>());
                    adj[ri1 * n + rj1].Add(new int[] { ri2, rj2 });
                }
            }
            for (int j = 0; j < n; j++)
            {
                IDictionary<int, int[]> num2index = new Dictionary<int, int[]>();
                for (int i = 0; i < m; i++)
                {
                    int num = matrix[i][j];
                    if (!num2index.ContainsKey(num))
                    {
                        num2index.Add(num, new int[] { i, j });
                    }
                    else
                    {
                        num2index[num] = new int[] { i, j };
                    }
                }
                IList<int> sortedArray = new List<int>(num2index.Keys);
                ((List<int>)sortedArray).Sort();
                for (int k = 1; k < sortedArray.Count; k++)
                {
                    int[] prev = num2index[sortedArray[k - 1]];
                    int[] curr = num2index[sortedArray[k]];
                    int i1 = prev[0], j1 = prev[1], i2 = curr[0], j2 = curr[1];
                    int[] root1 = uf.Find(i1, j1);
                    int[] root2 = uf.Find(i2, j2);
                    int ri1 = root1[0], rj1 = root1[1], ri2 = root2[0], rj2 = root2[1];
                    degree[ri2][rj2]++;
                    adj.TryAdd(ri1 * n + rj1, new List<int[]>());
                    adj[ri1 * n + rj1].Add(new int[] { ri2, rj2 });
                }
            }

            ISet<int> rootSet = new HashSet<int>();
            int[][] ranks = new int[m][];
            for (int i = 0; i < m; i++)
            {
                ranks[i] = new int[n];
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int[] rootArr = uf.Find(i, j);
                    int ri = rootArr[0], rj = rootArr[1];
                    rootSet.Add(ri * n + rj);
                    ranks[ri][rj] = 1;
                }
            }
            Queue<int[]> queue = new Queue<int[]>();
            foreach (int val in rootSet)
            {
                if (degree[val / n][val % n] == 0)
                {
                    queue.Enqueue(new int[] { val / n, val % n });
                }
            }
            while (queue.Count > 0)
            {
                int[] arr = queue.Dequeue();
                int i = arr[0], j = arr[1];
                if (!adj.ContainsKey(i * n + j))
                {
                    continue;
                }
                foreach (int[] adjArr in adj[i * n + j])
                {
                    int ui = adjArr[0], uj = adjArr[1];
                    degree[ui][uj]--;
                    if (degree[ui][uj] == 0)
                    {
                        queue.Enqueue(new int[] { ui, uj });
                    }
                    ranks[ui][uj] = Math.Max(ranks[ui][uj], ranks[i][j] + 1);
                }
            }
            int[][] res = new int[m][];
            for (int i = 0; i < m; i++)
            {
                res[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    int[] rootArr = uf.Find(i, j);
                    int ri = rootArr[0], rj = rootArr[1];
                    res[i][j] = ranks[ri][rj];
                }
            }
            return res;
        }
    }

    class UnionFind
    {
        int m, n;
        int[][][] root;
        int[][] size;

        public UnionFind(int m, int n)
        {
            this.m = m;
            this.n = n;
            this.root = new int[m][][];
            this.size = new int[m][];
            for (int i = 0; i < m; i++)
            {
                root[i] = new int[n][];
                for (int j = 0; j < n; j++)
                {
                    root[i][j] = new int[2];
                }
                size[i] = new int[n];
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    root[i][j][0] = i;
                    root[i][j][1] = j;
                    size[i][j] = 1;
                }
            }
        }

        public int[] Find(int i, int j)
        {
            int[] rootArr = root[i][j];
            int ri = rootArr[0], rj = rootArr[1];
            if (ri == i && rj == j)
            {
                return rootArr;
            }
            return Find(ri, rj);
        }

        public void Union(int i1, int j1, int i2, int j2)
        {
            int[] rootArr1 = Find(i1, j1);
            int[] rootArr2 = Find(i2, j2);
            int ri1 = rootArr1[0], rj1 = rootArr1[1];
            int ri2 = rootArr2[0], rj2 = rootArr2[1];
            if (ri1 != ri2 || rj1 != rj2)
            {
                if (size[ri1][rj1] >= size[ri2][rj2])
                {
                    root[ri2][rj2][0] = ri1;
                    root[ri2][rj2][1] = rj1;
                    size[ri1][rj1] += size[ri2][rj2];
                }
                else
                {
                    root[ri1][rj1][0] = ri2;
                    root[ri1][rj1][1] = rj2;
                    size[ri2][rj2] += size[ri1][rj1];
                }
            }
        }
    }
}
