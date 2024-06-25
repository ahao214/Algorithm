﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2732
{
    internal class Class2732
    {

        public IList<int> GoodSubsetofBinaryMatrix(int[][] grid)
        {
            IList<int> ans = new List<int>();
            IDictionary<int, int> dic = new Dictionary<int, int>();
            int m = grid.Length;
            int n = grid[0].Length;

            for (int j = 0; j < m; j++)
            {
                int st = 0;
                for (int i = 0; i < n; i++)
                {
                    st |= (grid[j][i] << i);
                }
                if (!dic.ContainsKey(st))
                {
                    dic.Add(st, j);
                }
                else
                {
                    dic[st] = j;
                }
            }

            if (dic.ContainsKey(0))
            {
                ans.Add(dic[0]);
                return ans;
            }

            foreach (KeyValuePair<int, int> pair1 in dic)
            {
                int x = pair1.Key, i = pair1.Value;
                foreach (KeyValuePair<int, int> pair2 in dic)
                {
                    int y = pair2.Key, j = pair2.Value;
                    if ((x & y) == 0)
                    {
                        IList<int> list = new List<int>();
                        list.Add(Math.Min(i, j));
                        list.Add(Math.Max(i, j));
                        return list;
                    }
                }
            }

            return ans;
        }




    }
}
