using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo757
{
    public class Class757
    {
        /// <summary>
        /// 方法一：贪心
        /// </summary>
        /// <param name="intervals"></param>
        /// <returns></returns>
        public int IntersectionSizeTwo(int[][] intervals)
        {
            int n = intervals.Length;
            int res = 0;
            int m = 2;
            Array.Sort(intervals, (a, b) => {
                if (a[0] == b[0])
                {
                    return b[1] - a[1];
                }
                return a[0] - b[0];
            });
            IList<int>[] temp = new IList<int>[n];
            for (int i = 0; i < n; i++)
            {
                temp[i] = new List<int>();
            }
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = intervals[i][0], k = temp[i].Count; k < m; j++, k++)
                {
                    res++;
                    Help(intervals, temp, i - 1, j);
                }
            }
            return res;
        }

        public void Help(int[][] intervals, IList<int>[] temp, int pos, int num)
        {
            for (int i = pos; i >= 0; i--)
            {
                if (intervals[i][1] < num)
                {
                    break;
                }
                temp[i].Add(num);
            }
        }

    }
}
