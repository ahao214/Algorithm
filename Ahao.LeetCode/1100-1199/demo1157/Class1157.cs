﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1157
{

    public class MajorityChecker
    {
        public const int K = 20;
        private int[] arr;
        private IDictionary<int, IList<int>> loc;
        private Random random;

        public MajorityChecker(int[] arr)
        {
            this.arr = arr;
            this.loc = new Dictionary<int, IList<int>>();
            for (int i = 0; i < arr.Length; ++i)
            {
                loc.TryAdd(arr[i], new List<int>());
                loc[arr[i]].Add(i);
            }
            this.random = new Random();
        }

        public int Query(int left, int right, int threshold)
        {
            int length = right - left + 1;

            for (int i = 0; i < K; ++i)
            {
                int x = arr[left + random.Next(length)];
                IList<int> pos = loc[x];
                int occ = SearchEnd(pos, right) - SearchStart(pos, left);
                if (occ >= threshold)
                {
                    return x;
                }
                else if (occ * 2 >= length)
                {
                    return -1;
                }
            }

            return -1;
        }

        private int SearchStart(IList<int> pos, int target)
        {
            int low = 0, high = pos.Count;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (pos[mid] >= target)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return low;
        }

        private int SearchEnd(IList<int> pos, int target)
        {
            int low = 0, high = pos.Count;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (pos[mid] > target)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return low;
        }


    }
}
