﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2713
{
    public class Class2713
    {
        public int MaxIncreasingCells(int[][] mat)
        {
            int m = mat.Length, n = mat[0].Length;
            IDictionary<int, IList<int[]>> dic = new Dictionary<int, IList<int[]>>();
            int[] row = new int[m];
            int[] col = new int[n];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dic.TryAdd(mat[i][j], new List<int[]>());
                    dic[mat[i][j]].Add(new int[] { i, j });
                }
            }
            IList<int> keys = new List<int>(dic.Keys);
            ((List<int>)keys).Sort();
            foreach (int key in keys)
            {
                IList<int[]> pos = dic[key];
                IList<int> res = new List<int>(); // 存放相同数值的答案，便于后续更新 row 和 col
                foreach (int[] arr in pos)
                {
                    res.Add(Math.Max(row[arr[0]], col[arr[1]]) + 1);
                }
                for (int i = 0; i < pos.Count; i++)
                {
                    int[] arr = pos[i];
                    int d = res[i];
                    row[arr[0]] = Math.Max(row[arr[0]], d);
                    col[arr[1]] = Math.Max(col[arr[1]], d);
                }
            }
            return row.Max();
        }

    }
}
