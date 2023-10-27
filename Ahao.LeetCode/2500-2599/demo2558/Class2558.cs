using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2558
{
    public class Class2558
    {
        public long PickGifts(int[] gifts, int k)
        {
            PriorityQueue<int, int> pq = new PriorityQueue<int, int>();
            foreach (int gift in gifts)
            {
                pq.Enqueue(gift, -gift);
            }
            while (k > 0)
            {
                k--;
                int x = pq.Dequeue();
                pq.Enqueue((int)Math.Sqrt(x), -(int)Math.Sqrt(x));
            }
            long res = 0;
            while (pq.Count > 0)
            {
                res += pq.Dequeue();
            }
            return res;
        }

        public long PickGifts2(int[] gifts, int k)
        {
            int n = gifts.Length;
            long res = 0;
            while (k > 0)
            {
                Array.Sort(gifts);
                k--;
                int val = Convert.ToInt32(Math.Floor(Math.Sqrt(gifts[n - 1])));
                gifts[n - 1] = val;
            }
            for (int i = 0; i < n; i++)
            {
                res += gifts[i];
            }
            return res;
        }

    }
}
