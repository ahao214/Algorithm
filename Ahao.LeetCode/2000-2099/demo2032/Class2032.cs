﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2000_2099.demo2032
{
    public class Class2032
    {
        public IList<int> TwoOutOfThree(int[] nums1, int[] nums2, int[] nums3)
        {
            IDictionary<int, int> dictionary = new Dictionary<int, int>();
            foreach (int i in nums1)
            {
                dictionary.TryAdd(i, 1);
            }
            foreach (int i in nums2)
            {
                dictionary.TryAdd(i, 0);
                dictionary[i] |= 2;
            }
            foreach (int i in nums3)
            {
                dictionary.TryAdd(i, 0);
                dictionary[i] |= 4;
            }
            IList<int> res = new List<int>();
            foreach (KeyValuePair<int, int> pair in dictionary)
            {
                int k = pair.Key, v = pair.Value;
                if ((v & (v - 1)) != 0)
                {
                    res.Add(k);
                }
            }
            return res;
        }
    }
}
