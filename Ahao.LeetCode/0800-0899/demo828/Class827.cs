﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo828
{
    public class Class828
    {
        public int UniqueLetterString(string s)
        {
            Dictionary<char, IList<int>> index = new Dictionary<char, IList<int>>();
            for (int i = 0; i < s.Length; i++)
            {
                if (!index.ContainsKey(s[i]))
                {
                    index.Add(s[i], new List<int>());
                    index[s[i]].Add(-1);
                }
                index[s[i]].Add(i);
            }
            int res = 0;
            foreach (KeyValuePair<char, IList<int>> pair in index)
            {
                IList<int> arr = pair.Value;
                arr.Add(s.Length);
                for (int i = 1; i < arr.Count - 1; i++)
                {
                    res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
                }
            }
            return res;
        }

    }
}
