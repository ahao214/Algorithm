using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1761
{
    public class Class1761
    {
        public int MinTrioDegree(int n, int[][] edges)
        {
            int[][] g = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                g[i] = new int[n];
            }
            int[] degree = new int[n];

            foreach (int[] edge in edges)
            {
                int x = edge[0] - 1, y = edge[1] - 1;
                g[x][y] = g[y][x] = 1;
                ++degree[x];
                ++degree[y];
            }

            int ans = int.MaxValue;
            for (int i = 0; i < n; ++i)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if (g[i][j] == 1)
                    {
                        for (int k = j + 1; k < n; ++k)
                        {
                            if (g[i][k] == 1 && g[j][k] == 1)
                            {
                                ans = Math.Min(ans, degree[i] + degree[j] + degree[k] - 6);
                            }
                        }
                    }
                }
            }

            return ans == int.MaxValue ? -1 : ans;
        }


        public int MinTrioDegree2(int n, int[][] edges)
        {
            // 原图
            ISet<int>[] g = new ISet<int>[n];
            for (int i = 0; i < n; ++i)
            {
                g[i] = new HashSet<int>();
            }
            // 定向后的图
            IList<int>[] h = new IList<int>[n];
            for (int i = 0; i < n; ++i)
            {
                h[i] = new List<int>();
            }
            int[] degree = new int[n];

            foreach (int[] edge in edges)
            {
                int x = edge[0] - 1, y = edge[1] - 1;
                g[x].Add(y);
                g[y].Add(x);
                ++degree[x];
                ++degree[y];
            }
            foreach (int[] edge in edges)
            {
                int x = edge[0] - 1, y = edge[1] - 1;
                if (degree[x] < degree[y] || (degree[x] == degree[y] && x < y))
                {
                    h[x].Add(y);
                }
                else
                {
                    h[y].Add(x);
                }
            }

            int ans = int.MaxValue;
            for (int i = 0; i < n; ++i)
            {
                foreach (int j in h[i])
                {
                    foreach (int k in h[j])
                    {
                        if (g[i].Contains(k))
                        {
                            ans = Math.Min(ans, degree[i] + degree[j] + degree[k] - 6);
                        }
                    }
                }
            }

            return ans == int.MaxValue ? -1 : ans;
        }



    }
}
