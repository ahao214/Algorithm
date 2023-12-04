using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2477
{
    public class Class2477
    {
        long res = 0;

        public long MinimumFuelCost(int[][] roads, int seats)
        {
            int n = roads.Length;
            IList<int>[] g = new IList<int>[n + 1];
            for (int i = 0; i <= n; i++)
            {
                g[i] = new List<int>();
            }
            foreach (int[] e in roads)
            {
                g[e[0]].Add(e[1]);
                g[e[1]].Add(e[0]);
            }
            DFS(0, -1, seats, g);
            return res;
        }

        public int DFS(int cur, int fa, int seats, IList<int>[] g)
        {
            int peopleSum = 1;
            foreach (int ne in g[cur])
            {
                if (ne != fa)
                {
                    int peopleCnt = DFS(ne, cur, seats, g);
                    peopleSum += peopleCnt;
                    res += (peopleCnt + seats - 1) / seats;
                }
            }
            return peopleSum;
        }

    }
}
