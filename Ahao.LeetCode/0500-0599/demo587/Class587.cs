using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo587
{
    public class Class587
    {
        #region 方法一: Jarvis 算法


        public int[][] OuterTrees(int[][] trees)
        {
            int n = trees.Length;
            if (n < 4)
            {
                return trees;
            }
            int leftMost = 0;
            for (int i = 0; i < n; i++)
            {
                if (trees[i][0] < trees[leftMost][0])
                {
                    leftMost = i;
                }
            }

            IList<int[]> res = new List<int[]>();
            bool[] visit = new bool[n];
            int p = leftMost;
            do
            {
                int q = (p + 1) % n;
                for (int r = 0; r < n; r++)
                {
                    /* 如果 r 在 pq 的右侧，则 q = r */
                    if (Cross(trees[p], trees[q], trees[r]) < 0)
                    {
                        q = r;
                    }
                }
                /* 是否存在点 i, 使得 p 、q 、i 在同一条直线上 */
                for (int i = 0; i < n; i++)
                {
                    if (visit[i] || i == p || i == q)
                    {
                        continue;
                    }
                    if (Cross(trees[p], trees[q], trees[i]) == 0)
                    {
                        res.Add(trees[i]);
                        visit[i] = true;
                    }
                }
                if (!visit[q])
                {
                    res.Add(trees[q]);
                    visit[q] = true;
                }
                p = q;
            } while (p != leftMost);
            return res.ToArray();
        }

        public int Cross(int[] p, int[] q, int[] r)
        {
            return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
        }


        #endregion
    }
}
