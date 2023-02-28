﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2363
{
    public class Class2363
    {

        public IList<IList<int>> MergeSimilarItems(int[][] items1, int[][] items2)
        {
            IDictionary<int, int> dictionary = new Dictionary<int, int>();
            foreach (int[] v in items1)
            {
                dictionary.TryAdd(v[0], 0);
                dictionary[v[0]] += v[1];
            }
            foreach (int[] v in items2)
            {
                dictionary.TryAdd(v[0], 0);
                dictionary[v[0]] += v[1];
            }

            IList<IList<int>> res = new List<IList<int>>();
            foreach (KeyValuePair<int, int> kv in dictionary)
            {
                int k = kv.Key, v = kv.Value;
                res.Add(new List<int> { k, v });
            }
            ((List<IList<int>>)res).Sort((a, b) => a[0] - b[0]);
            return res;
        }

    }
}
