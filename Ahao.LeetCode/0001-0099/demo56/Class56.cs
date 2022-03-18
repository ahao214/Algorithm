using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo56
{
    /*
     56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
     */
    public class Class56
    {
        public int[][] Merge(int[][] intervals)
        {
            if (intervals == null)
                throw new ArgumentNullException();
            var input = intervals.Where(t => t != null && t.Length == 2).OrderBy(t => t[0]).ToList();
            var output = new List<int[]>(input.Count);
            if (input.Count == 0)
                return output.ToArray();
            var pre = input[0];
            for (int i = 1; i < input.Count; i++)
            {
                if (CanMerge(pre, input[i]))
                {
                    pre = Merge(pre, input[i]);
                }
                else
                {
                    output.Add(pre);
                    pre = input[i];
                }
            }
            output.Add(pre);
            return output.ToArray();
        }

        private int[] Merge(int[] x, int[] y)
        {
            return new[] { Math.Min(x[0], y[0]), Math.Max(x[1], y[1]) };
        }

        private bool CanMerge(int[] x, int[] y)
        {
            return x[1] >= y[0] && y[1] >= x[0];
        }
    }
}
