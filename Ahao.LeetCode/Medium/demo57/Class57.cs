using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo57
{
    /*
     57. 插入区间
给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
     */
    public class Class57
    {
        public int[][] Insert(int[][] intervals, int[] newInterval)
        {
            List<int[]> ans = new List<int[]>();
            int n = intervals.Length;
            int start = -1, end = -1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (newInterval[0] > intervals[i][j] || (j == 0 && newInterval[0] == intervals[i][j]))
                    {
                        start = i * 2 + j;
                    }
                    if (newInterval[1] > intervals[i][j] || (j == 0 && newInterval[1] == intervals[i][j]))
                    {
                        end = i * 2 + j;
                    }
                }
            }
            end++;
            int i1 = start / 2, i2 = end / 2;
            if (start == -1)
            {
                i1 = -1;
            }
            int j1 = start % 2, j2 = end % 2;
            if (i1 == i2)
            {
                return intervals;
            }
            else
            {
                if (j1 == 0)//遍历的时候左边不加等于号
                {
                    if (j2 == 0) //遍历的时候右边加等于号
                    {
                        for (int i = 0; i < i1; i++)
                        {
                            ans.Add(intervals[i]);
                        }
                        ans.Add(new int[2] { intervals[i1][0], newInterval[1] });
                        for (int i = i2; i < n; i++)
                        {
                            ans.Add(intervals[i]);
                        }
                        return ans.ToArray();
                    }
                    else//遍历的时候右边不加等于号
                    {
                        for (int i = 0; i < i1; i++)
                        {
                            ans.Add(intervals[i]);
                        }
                        ans.Add(new int[2] { intervals[i1][0], intervals[i2][1] });
                        for (int i = i2 + 1; i < n; i++)
                        {
                            ans.Add(intervals[i]);
                        }
                        return ans.ToArray();
                    }
                }
                else//遍历的时候左边加等于号
                {
                    if (j2 == 0) //遍历的时候右边加等于号
                    {
                        for (int i = 0; i <= i1; i++)
                        {
                            ans.Add(intervals[i]);
                        }
                        ans.Add(newInterval);
                        for (int i = i2; i < n; i++)
                        {
                            ans.Add(intervals[i]);
                        }
                        return ans.ToArray();
                    }
                    else//遍历的时候右边不加加等于号
                    {
                        for (int i = 0; i <= i1; i++)
                        {
                            ans.Add(intervals[i]);
                        }
                        ans.Add(new int[2] { newInterval[0], intervals[i2][1] });
                        for (int i = i2 + 1; i < n; i++)
                        {
                            ans.Add(intervals[i]);
                        }
                        return ans.ToArray();
                    }
                }
            }
        }
    }
}
