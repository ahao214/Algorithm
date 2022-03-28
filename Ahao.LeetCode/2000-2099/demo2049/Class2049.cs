﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo2049
{
    public class Class2049
    {
        long maxScore = 0;
        int cnt = 0;
        int n;
        IList<int>[] children;

        public int CountHighestScoreNodes(int[] parents)
        {
            n = parents.Length;
            children = new IList<int>[n];
            for (int i = 0; i < n; i++)
            {
                children[i] = new List<int>();
            }
            for (int i = 0; i < n; i++)
            {
                int p = parents[i];
                if (p != -1)
                {
                    children[p].Add(i);
                }
            }
            DFS(0);
            return cnt;
        }

        public int DFS(int node)
        {
            long score = 1;
            int size = n - 1;
            foreach (int c in children[node])
            {
                int t = DFS(c);
                score *= t;
                size -= t;
            }
            if (node != 0)
            {
                score *= size;
            }
            if (score == maxScore)
            {
                cnt++;
            }
            else if (score > maxScore)
            {
                maxScore = score;
                cnt = 1;
            }
            return n - size;
        }
    }
}
