﻿using System;
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
    }
}
