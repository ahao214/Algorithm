using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1499
{
    internal class Class1499
    {

        public int FindMaxValueOfEquation(int[][] points, int k)
        {
            int res = int.MinValue;
            PriorityQueue<Tuple<int, int>, int> heap = new PriorityQueue<Tuple<int, int>, int>();
            foreach (int[] point in points)
            {
                int x = point[0], y = point[1];
                while (heap.Count > 0 && x - heap.Peek().Item2 > k)
                {
                    heap.Dequeue();
                }
                if (heap.Count > 0)
                {
                    res = Math.Max(res, x + y - heap.Peek().Item1);
                }
                heap.Enqueue(new Tuple<int, int>(x - y, x), x - y);
            }
            return res;
        }

    }
}
