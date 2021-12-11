﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo911
{
    /// <summary>
    /// 911. 在线选举
    /// </summary>
    public class TopVotedCandidate
    {
        IList<int> tops;
        Dictionary<int, int> voteCounts;
        int[] times;

        public TopVotedCandidate(int[] persons, int[] times)
        {
            tops = new List<int>();
            voteCounts = new Dictionary<int, int>();
            voteCounts.Add(-1, -1);
            int top = -1;
            for (int i = 0; i < persons.Length; ++i)
            {
                int p = persons[i];
                if (!voteCounts.ContainsKey(p))
                {
                    voteCounts.Add(p, 0);
                }
                else
                {
                    ++voteCounts[p];
                }
                if (voteCounts[p] >= voteCounts[top])
                {
                    top = p;
                }
                tops.Add(top);
            }
            this.times = times;
        }

        public int Q(int t)
        {
            int l = 0, r = times.Length - 1;
            // 找到满足 times[l] <= t 的最大的 l
            while (l < r)
            {
                int m = l + (r - l + 1) / 2;
                if (times[m] <= t)
                {
                    l = m;
                }
                else
                {
                    r = m - 1;
                }
            }
            return tops[l];
        }
    }
}
