﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2611
{
    public class Class2611
    {
        public int MiceAndCheese(int[] reward1, int[] reward2, int k)
        {
            int sum = reward2.Sum();
            int n = reward1.Length;
            int[] diff = new int[n];
            for (int i = 0; i < n; i++)
            {
                diff[i] = reward1[i] - reward2[i];
            }
            int res = sum;
            Array.Sort(diff);
            for (int i = n - k; i < n; i++)
            {
                res += diff[i];
            }
            return res;
        }


        /*         
        public int MiceAndCheese2(int[] reward1, int[] reward2, int k)
        {
            int ans = 0;
            int n = reward1.Length;
            PriorityQueue<int, int> pq = new PriorityQueue<int, int>();
            for (int i = 0; i < n; i++)
            {
                ans += reward2[i];
                pq.Enqueue(reward1[i] - reward2[i], reward1[i] - reward2[i]);
                if (pq.Count > k)
                {
                    pq.Dequeue();
                }
            }
            while (pq.Count > 0)
            {
                ans += pq.Dequeue();
            }
            return ans;
        }
        */

    }
}
