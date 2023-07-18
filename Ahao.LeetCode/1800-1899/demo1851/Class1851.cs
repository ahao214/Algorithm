﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1851
{
    internal class Class1851
    {

        public int[] MinInterval(int[][] intervals, int[] queries)
        {
            int[] qindex = new int[queries.Length];
            for (int idx = 0; idx < queries.Length; idx++)
            {
                qindex[idx] = idx;
            }
            Array.Sort(qindex, (i, j) => queries[i] - queries[j]);
            Array.Sort(intervals, (i, j) => i[0] - j[0]);
            PriorityQueue<int[], int> pq = new PriorityQueue<int[], int>();
            int[] res = new int[queries.Length];
            Array.Fill(res, -1);
            int i = 0;
            foreach (int qi in qindex)
            {
                while (i < intervals.Length && intervals[i][0] <= queries[qi])
                {
                    pq.Enqueue(new int[] { intervals[i][1] - intervals[i][0] + 1, intervals[i][0], intervals[i][1] }, intervals[i][1] - intervals[i][0] + 1);
                    i++;
                }
                while (pq.Count > 0 && pq.Peek()[2] < queries[qi])
                {
                    pq.Dequeue();
                }
                if (pq.Count > 0)
                {
                    res[qi] = pq.Peek()[0];
                }
            }
            return res;
        }

    }
}
