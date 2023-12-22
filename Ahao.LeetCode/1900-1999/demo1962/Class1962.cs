using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1900_1999.demo1962
{
    public class Class1962
    {

        public int MinStoneSum(int[] piles, int k)
        {
            PriorityQueue<int, int> pq = new PriorityQueue<int, int>();
            foreach (int pile in piles)
            {
                pq.Enqueue(pile, -pile);
            }
            for (int i = 0; i < k; i++)
            {
                int pile = pq.Dequeue();
                pile -= pile / 2;
                pq.Enqueue(pile, -pile);
            }
            int sum = 0;
            while (pq.Count > 0)
            {
                sum += pq.Dequeue();
            }
            return sum;
        }
    }
}
