using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2603
{
    internal class Class2603
    {
        public int CollectTheCoins(int[] coins, int[][] edges)
        {
            int n = coins.Length;
            IList<int>[] g = new IList<int>[n];
            for (int i = 0; i < n; ++i)
            {
                g[i] = new List<int>();
            }
            int[] degree = new int[n];
            foreach (int[] edge in edges)
            {
                int x = edge[0], y = edge[1];
                g[x].Add(y);
                g[y].Add(x);
                ++degree[x];
                ++degree[y];
            }

            int rest = n;
            /* 删除树中所有无金币的叶子节点，直到树中所有的叶子节点都是含有金币的 */
            Queue<int> queue = new Queue<int>();
            for (int i = 0; i < n; ++i)
            {
                if (degree[i] == 1 && coins[i] == 0)
                {
                    queue.Enqueue(i);
                }
            }
            while (queue.Count > 0)
            {
                int u = queue.Dequeue();
                --degree[u];
                --rest;
                foreach (int v in g[u])
                {
                    --degree[v];
                    if (degree[v] == 1 && coins[v] == 0)
                    {
                        queue.Enqueue(v);
                    }
                }
            }
            /* 删除树中所有的叶子节点, 连续删除2次 */
            for (int x = 0; x < 2; ++x)
            {
                queue = new Queue<int>();
                for (int i = 0; i < n; ++i)
                {
                    if (degree[i] == 1)
                    {
                        queue.Enqueue(i);
                    }
                }
                while (queue.Count > 0)
                {
                    int u = queue.Dequeue();
                    --degree[u];
                    --rest;
                    foreach (int v in g[u])
                    {
                        --degree[v];
                    }
                }
            }

            return rest == 0 ? 0 : (rest - 1) * 2;
        }

    }
}
