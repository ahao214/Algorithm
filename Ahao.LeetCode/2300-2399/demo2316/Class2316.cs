using System;
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




        Dictionary<int, List<int>> m;
        bool[] visited;
        int count;
        public long CountPairs2(int n, int[][] edges)
        {
            // vector<int> groups;
            visited = new bool[n];
            m = new Dictionary<int, List<int>>();
            foreach (var v in edges)
            {
                if (!m.ContainsKey(v[0]))
                {
                    m.Add(v[0], new List<int>() { v[1] });
                }
                else
                {
                    m[v[0]].Add(v[1]);
                }
                if (!m.ContainsKey(v[1]))
                {
                    m.Add(v[1], new List<int>() { v[0] });
                }
                else
                {
                    m[v[1]].Add(v[0]);
                }
            }
            long ret = 0;
            int counted = 0;
            for (int i = 0; i < n; ++i)
            {
                if (visited[i])
                {
                    continue;
                }
                count = 0;

                // dfs(i);
                var q = new Queue<int>();
                q.Enqueue(i);
                visited[i] = true;
                while (q.Count > 0)
                {
                    var point = q.Dequeue();
                    ++count;
                    if (!m.ContainsKey(point))
                    {
                        continue;
                    }
                    foreach (var p in m[point])
                    {
                        if (visited[p])
                        {
                            continue;
                        }
                        q.Enqueue(p);
                        visited[p] = true;
                    }
                }

                counted += count;
                ret += 1L * count * (n - counted);
            }

            return ret;
        }

        void dfs(int point)
        {
            if (!m.ContainsKey(point))
            {
                return;
            }
            foreach (var p in m[point])
            {
                if (visited[p])
                {
                    continue;
                }
                ++count;
                visited[p] = true;
                dfs(p);
            }
        }






        static int n = 100010;
        int[] p = new int[n];
        int[] size = new int[n];

        int find(int x)
        {
            if (p[x] != x)
            {
                p[x] = find(p[x]);
            }
            return p[x];
        }

        void union(int a, int b)
        {
            int fa = find(a), fb = find(b);
            if (fa != fb)
            {
                p[fa] = fb;
                size[fb] += size[fa];
            }
        }

        public long CountPairs3(int n, int[][] edges)
        {
            long res = 0;

            for (int i = 0; i < n; i++)
            {
                p[i] = i;
                size[i] = 1;
            }

            foreach (var edge in edges)
            {
                union(edge[0], edge[1]);
            }
            List<int> list = new List<int>();
            for (int i = 0; i < n; i++)
            {
                if (p[i] == i)
                {
                    list.Add(size[i]);
                }
            }
            int m = list.Count;
            for (int i = 0; i < m - 1; i++)
            {
                n -= list[i];
                res += (long)list[i] * n;

            }

            return res;
        }
    }
}
