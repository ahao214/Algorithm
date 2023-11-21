using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2200_2299.demo2208
{
    internal class Class2216
    {

        public int HalveArray(int[] nums)
        {
            PriorityQueue<double, double> pq = new PriorityQueue<double, double>();
            foreach (int num in nums)
            {
                pq.Enqueue(num, -num);
            }
            int res = 0;
            double sum = 0;
            foreach (int num in nums)
            {
                sum += num;
            }
            double sum2 = 0.0;
            while (sum2 < sum / 2)
            {
                double x = pq.Dequeue();
                sum2 += x / 2;
                pq.Enqueue(x / 2, -x / 2);
                res++;
            }
            return res;
        }
    }
}
