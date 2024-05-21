﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2200_2299.demo2225
{
    public class Class2225
    {
        public IList<IList<int>> FindWinners(int[][] matches)
        {
            IDictionary<int, int> freq = new Dictionary<int, int>();
            foreach (int[] match in matches)
            {
                int winner = match[0], loser = match[1];
                freq.TryAdd(winner, 0);
                freq.TryAdd(loser, 0);
                ++freq[loser];
            }

            IList<IList<int>> ans = new List<IList<int>>();
            for (int i = 0; i < 2; ++i)
            {
                ans.Add(new List<int>());
            }
            foreach (KeyValuePair<int, int> pair in freq)
            {
                if (pair.Value < 2)
                {
                    ans[pair.Value].Add(pair.Key);
                }
            }

            ((List<int>)ans[0]).Sort();
            ((List<int>)ans[1]).Sort();
            return ans;
        }


    }
}
