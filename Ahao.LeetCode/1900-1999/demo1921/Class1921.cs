using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1900_1999.demo1921
{
    public class Class1921
    {
        public int EliminateMaximum(int[] dist, int[] speed)
        {
            int n = dist.Length;
            int[] minTime = new int[n];
            for (int i = 0; i < n; i++)
            {
                minTime[i] = (dist[i] - 1) / speed[i] + 1;
            }
            Array.Sort(minTime);

            for (int i = 0; i < n; i++)
            {
                if (minTime[i] <= i)
                {
                    return i;
                }
            }
            return n;
        }

    }
}
