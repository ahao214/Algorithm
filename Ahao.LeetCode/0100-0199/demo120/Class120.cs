﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo120
{
    /// <summary>
    /// 120. 三角形最小路径和
    /// </summary>
    public class Class120
    {
        public int MinimumTotal(IList<IList<int>> triangle)
        {
            return MinimumTotal(triangle, 0, 0);
        }

        private int MinimumTotal(IList<IList<int>> triangle, int i, int j)
        {
            if (i == triangle.Count)
            {
                return 0;
            }
            return Math.Min(MinimumTotal(triangle, i + 1, j), MinimumTotal(triangle, i + 1, j + 1)) + triangle[i][j];
        }

        public int MinimumTotal1(IList<IList<int>> triangle)
        {
            var cache = new Dictionary<(int i, int j), int>();
            return MinimumTotal1(triangle, 0, 0, cache);
        }

        private int MinimumTotal1(IList<IList<int>> triangle, int i, int j, Dictionary<(int i, int j), int> cache)
        {
            if (i == triangle.Count)
            {
                return 0;
            }

            if (cache.TryGetValue((i, j), out var result))
            {
                return result;
            }
            result = Math.Min(MinimumTotal1(triangle, i + 1, j, cache), MinimumTotal1(triangle, i + 1, j + 1, cache)) + triangle[i][j];
            cache.Add((i, j), result);
            return result;
        }


        public int MinimumTotal2(IList<IList<int>> triangle)
        {
            var v = triangle;
            var m = new int[v.Count][];
            m[v.Count - 1] = v[v.Count - 1].ToArray();
            for (int i = v.Count - 2; i >= 0; i--)
            {
                m[i] = new int[m[i + 1].Length - 1];
                for (int j = 0; j < m[i].Length; j++)
                {
                    m[i][j] = Math.Min(m[i + 1][j], m[i + 1][j + 1]) + v[i][j];
                }
            }
            return m[0][0];
        }

        public int MinimumTotal3(IList<IList<int>> triangle)
        {
            var v = triangle;
            var m = v[v.Count - 1].ToArray();
            for (int i = v.Count - 2; i >= 0; i--)
            {
                for (int j = 0; j <= i; j++)
                {
                    m[j] = Math.Min(m[j], m[j + 1]) + v[i][j];
                }
            }
            return m[0];
        }

    }
}
