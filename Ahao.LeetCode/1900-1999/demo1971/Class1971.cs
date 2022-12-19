using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1900_1999.demo1971
{
    public class Class1971
    {
        /// <summary>
        /// 广度优先
        /// </summary>
        /// <param name="n"></param>
        /// <param name="edges"></param>
        /// <param name="source"></param>
        /// <param name="destination"></param>
        /// <returns></returns>
        public bool ValidPath(int n, int[][] edges, int source, int destination)
        {
            IList<int>[] adj = new IList<int>[n];
            for (int i = 0; i < n; i++)
            {
                adj[i] = new List<int>();
            }
            foreach (int[] edge in edges)
            {
                int x = edge[0], y = edge[1];
                adj[x].Add(y);
                adj[y].Add(x);
            }
            bool[] visited = new bool[n];
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(source);
            visited[source] = true;
            while (queue.Count > 0)
            {
                int vertex = queue.Dequeue();
                if (vertex == destination)
                {
                    break;
                }
                foreach (int next in adj[vertex])
                {
                    if (!visited[next])
                    {
                        queue.Enqueue(next);
                        visited[next] = true;
                    }
                }
            }
            return visited[destination];
        }


        /// <summary>
        /// 深度优先
        /// </summary>
        /// <param name="n"></param>
        /// <param name="edges"></param>
        /// <param name="source"></param>
        /// <param name="destination"></param>
        /// <returns></returns>
        public bool ValidPath2(int n, int[][] edges, int source, int destination)
        {
            IList<int>[] adj = new IList<int>[n];
            for (int i = 0; i < n; i++)
            {
                adj[i] = new List<int>();
            }
            foreach (int[] edge in edges)
            {
                int x = edge[0], y = edge[1];
                adj[x].Add(y);
                adj[y].Add(x);
            }
            bool[] visited = new bool[n];
            return DFS(source, destination, adj, visited);
        }

        public bool DFS(int source, int destination, IList<int>[] adj, bool[] visited)
        {
            if (source == destination)
            {
                return true;
            }
            visited[source] = true;
            foreach (int next in adj[source])
            {
                if (!visited[next] && DFS(next, destination, adj, visited))
                {
                    return true;
                }
            }
            return false;
        }
    }
}
