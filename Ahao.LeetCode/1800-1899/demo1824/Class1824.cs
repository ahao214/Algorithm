using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1824
{
    public class Class1824
    {
        const int INF = 0x3fffffff;

        public int MinSideJumps(int[] obstacles)
        {
            int n = obstacles.Length - 1;
            int[] d = new int[3];
            Array.Fill(d, 1);
            d[1] = 0;
            for (int i = 1; i <= n; i++)
            {
                int minCnt = INF;
                for (int j = 0; j < 3; j++)
                {
                    if (j == obstacles[i] - 1)
                    {
                        d[j] = INF;
                    }
                    else
                    {
                        minCnt = Math.Min(minCnt, d[j]);
                    }
                }
                for (int j = 0; j < 3; j++)
                {
                    if (j == obstacles[i] - 1)
                    {
                        continue;
                    }
                    d[j] = Math.Min(d[j], minCnt + 1);
                }
            }
            return Math.Min(Math.Min(d[0], d[1]), d[2]);
        }

    }
}
