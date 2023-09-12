using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1462
{
    internal class Class1462
    {
        public IList<bool> CheckIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries)
        {
            IList<int>[] g = new IList<int>[numCourses];
            for (int i = 0; i < numCourses; i++)
            {
                g[i] = new List<int>();
            }
            int[] indgree = new int[numCourses];
            bool[][] isPre = new bool[numCourses][];
            for (int i = 0; i < numCourses; i++)
            {
                isPre[i] = new bool[numCourses];
            }
            foreach (int[] p in prerequisites)
            {
                ++indgree[p[1]];
                g[p[0]].Add(p[1]);
            }
            Queue<int> queue = new Queue<int>();
            for (int i = 0; i < numCourses; ++i)
            {
                if (indgree[i] == 0)
                {
                    queue.Enqueue(i);
                }
            }
            while (queue.Count > 0)
            {
                int cur = queue.Dequeue();
                foreach (int ne in g[cur])
                {
                    isPre[cur][ne] = true;
                    for (int i = 0; i < numCourses; ++i)
                    {
                        isPre[i][ne] = isPre[i][ne] | isPre[i][cur];
                    }
                    --indgree[ne];
                    if (indgree[ne] == 0)
                    {
                        queue.Enqueue(ne);
                    }
                }
            }
            IList<bool> res = new List<bool>();
            foreach (int[] query in queries)
            {
                res.Add(isPre[query[0]][query[1]]);
            }
            return res;
        }


        public IList<bool> CheckIfPrerequisite2(int numCourses, int[][] prerequisites, int[][] queries)
        {
            IList<int>[] g = new IList<int>[numCourses];
            for (int i = 0; i < numCourses; i++)
            {
                g[i] = new List<int>();
            }
            bool[] vi = new bool[numCourses];
            bool[][] isPre = new bool[numCourses][];
            for (int i = 0; i < numCourses; i++)
            {
                isPre[i] = new bool[numCourses];
            }
            foreach (int[] p in prerequisites)
            {
                g[p[0]].Add(p[1]);
            }
            for (int i = 0; i < numCourses; ++i)
            {
                DFS(g, isPre, vi, i);
            }
            IList<bool> res = new List<bool>();
            foreach (int[] query in queries)
            {
                res.Add(isPre[query[0]][query[1]]);
            }
            return res;
        }

        public void DFS(IList<int>[] g, bool[][] isPre, bool[] vi, int cur)
        {
            if (vi[cur])
            {
                return;
            }
            vi[cur] = true;
            foreach (int ne in g[cur])
            {
                DFS(g, isPre, vi, ne);
                isPre[cur][ne] = true;
                for (int i = 0; i < isPre.Length; ++i)
                {
                    isPre[cur][i] = isPre[cur][i] | isPre[ne][i];
                }
            }
        }



    }
}
