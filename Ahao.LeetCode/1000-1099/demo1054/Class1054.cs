using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1054
{
    public class Class1054
    {

        public int[] RearrangeBarcodes(int[] barcodes)
        {
            IDictionary<int, int> count = new Dictionary<int, int>();
            foreach (int b in barcodes)
            {
                count.TryAdd(b, 0);
                count[b]++;
            }
            PriorityQueue<Tuple<int, int>, int> pq = new PriorityQueue<Tuple<int, int>, int>();
            foreach (KeyValuePair<int, int> pair in count)
            {
                pq.Enqueue(new Tuple<int, int>(pair.Value, pair.Key), -pair.Value);
            }
            int n = barcodes.Length;
            int[] res = new int[n];
            for (int i = 0; i < n; ++i)
            {
                Tuple<int, int> p = pq.Dequeue();
                int cx = p.Item1, x = p.Item2;
                if (i == 0 || res[i - 1] != x)
                {
                    res[i] = x;
                    if (cx > 1)
                    {
                        pq.Enqueue(new Tuple<int, int>(cx - 1, x), 1 - cx);
                    }
                }
                else
                {
                    Tuple<int, int> p2 = pq.Dequeue();
                    int cy = p2.Item1, y = p2.Item2;
                    res[i] = y;
                    if (cy > 1)
                    {
                        pq.Enqueue(new Tuple<int, int>(cy - 1, y), 1 - cy);
                    }
                    pq.Enqueue(new Tuple<int, int>(cx, x), -cx);
                }
            }
            return res;
        }




        public int[] RearrangeBarcodes2(int[] barcodes)
        {
            int length = barcodes.Length;
            if (length < 2)
            {
                return barcodes;
            }

            IDictionary<int, int> counts = new Dictionary<int, int>();
            int maxCount = 0;
            foreach (int b in barcodes)
            {
                counts.TryAdd(b, 0);
                counts[b]++;
                maxCount = Math.Max(maxCount, counts[b]);
            }

            int evenIndex = 0;
            int oddIndex = 1;
            int halfLength = length / 2;
            int[] res = new int[length];
            foreach (KeyValuePair<int, int> pair in counts)
            {
                int x = pair.Key;
                int count = pair.Value;
                while (count > 0 && count <= halfLength && oddIndex < length)
                {
                    res[oddIndex] = x;
                    count--;
                    oddIndex += 2;
                }
                while (count > 0)
                {
                    res[evenIndex] = x;
                    count--;
                    evenIndex += 2;
                }
            }
            return res;
        }

    }
}
