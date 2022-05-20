using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo436
{
    public class Class436
    {
        /// <summary>
        /// 二分查找
        /// </summary>
        /// <param name="intervals"></param>
        /// <returns></returns>

        public int[] FindRightInterval(int[][] intervals)
        {
            int n = intervals.Length;
            int[][] startIntervals = new int[n][];
            for (int i = 0; i < n; i++)
            {
                startIntervals[i] = new int[2];
                startIntervals[i][0] = intervals[i][0];
                startIntervals[i][1] = i;
            }
            Array.Sort(startIntervals, (o1, o2) => o1[0] - o2[0]);

            int[] ans = new int[n];
            for (int i = 0; i < n; i++)
            {
                int left = 0;
                int right = n - 1;
                int target = -1;
                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    if (startIntervals[mid][0] >= intervals[i][1])
                    {
                        target = startIntervals[mid][1];
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
                ans[i] = target;
            }
            return ans;
        }



        /// <summary>
        /// 双指针
        /// </summary>
        /// <param name="intervals"></param>
        /// <returns></returns>
        public int[] FindRightInterval2(int[][] intervals)
        {
            int n = intervals.Length;
            int[][] startIntervals = new int[n][];
            int[][] endIntervals = new int[n][];
            for (int i = 0; i < n; i++)
            {
                startIntervals[i] = new int[2];
                startIntervals[i][0] = intervals[i][0];
                startIntervals[i][1] = i;
                endIntervals[i] = new int[2];
                endIntervals[i][0] = intervals[i][1];
                endIntervals[i][1] = i;
            }
            Array.Sort(startIntervals, (o1, o2) => o1[0] - o2[0]);
            Array.Sort(endIntervals, (o1, o2) => o1[0] - o2[0]);

            int[] ans = new int[n];
            for (int i = 0, j = 0; i < n; i++)
            {
                while (j < n && endIntervals[i][0] > startIntervals[j][0])
                {
                    j++;
                }
                if (j < n)
                {
                    ans[endIntervals[i][1]] = startIntervals[j][1];
                }
                else
                {
                    ans[endIntervals[i][1]] = -1;
                }
            }
            return ans;
        }



    }
}
