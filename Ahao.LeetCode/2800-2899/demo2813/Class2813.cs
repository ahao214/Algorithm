﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2800_2899.demo2813
{
    internal class Class2813
    {

        public long FindMaximumElegance(int[][] items, int k)
        {
            Array.Sort(items, (item0, item1) => item1[0] - item0[0]);
            ISet<int> categorySet = new HashSet<int>();
            long profit = 0, res = 0;
            Stack<int> st = new Stack<int>();
            for (int i = 0; i < items.Length; i++)
            {
                if (i < k)
                {
                    profit += items[i][0];
                    if (!categorySet.Add(items[i][1]))
                    {
                        st.Push(items[i][0]);
                    }
                }
                else if (st.Count > 0 && categorySet.Add(items[i][1]))
                {
                    profit += items[i][0] - st.Pop();
                }
                res = Math.Max(res, profit + (long)categorySet.Count * categorySet.Count);
            }
            return res;
        }

    }
}
