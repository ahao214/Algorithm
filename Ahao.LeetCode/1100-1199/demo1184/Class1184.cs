using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1184
{
    public class Class1184
    {
        public int DistanceBetweenBusStops(int[] distance, int start, int destination)
        {
            if (start > destination)
            {
                int tmp = start;
                start = destination;
                destination = tmp;
            }

            int sum1 = 0, sum2 = 0;
            for (int i = 0; i < distance.Length; i++)
            {
                if (i >= start && i < destination)
                {
                    sum1 += distance[i];
                }
                else
                {
                    sum2 += distance[i];
                }
            }
            return Math.Min(sum1, sum2);
        }
    }
}
