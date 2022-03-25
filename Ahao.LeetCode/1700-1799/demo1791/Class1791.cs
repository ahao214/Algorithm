using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1791
{
    public class Class1791
    {
        public int FindCenter(int[][] edges)
        {
            if (edges[0][0] == edges[1][0])
                return edges[0][0];
            else if (edges[0][1] == edges[1][0])
                return edges[0][1];
            else if (edges[0][0] == edges[1][1])
                return edges[0][0];
            else if (edges[0][1] == edges[1][1])
                return edges[0][1];
            else
                return -1;
        }

        public int FindCenter1(int[][] edges)
        {
            int n = edges.Length + 1;
            int[] degrees = new int[n + 1];
            foreach (int[] edge in edges)
            {
                degrees[edge[0]]++;
                degrees[edge[1]]++;
            }
            for (int i = 1; i <= n; i++)
            {
                if (degrees[i] == n - 1)
                {
                    return i;
                }
            }
            return 0;
        }
    }
}
