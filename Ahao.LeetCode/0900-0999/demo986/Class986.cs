using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.LC986
{
    /// <summary>
    /// 986. 区间列表的交集
    /// </summary>
    public class Class986
    {
        public int[][] IntervalIntersection(int[][] firstList, int[][] secondList)
        {
            List<int[]> ans = new List<int[]>();
            if (firstList == null || firstList.Length == 0 || secondList == null || secondList.Length == 0)
            {
                return ans.ToArray();
            }

            int i = 0, j = 0, firstLen = firstList.Length, secondLen = secondList.Length;


            while (i < firstLen && j < secondLen)
            {
                int start1 = firstList[i][0], end1 = firstList[i][1];
                int start2 = secondList[j][0], end2 = secondList[j][1];
                //选择开始时间晚的
                int start = Math.Max(start1, start2);
                //选择结束时间早的
                int end = Math.Min(end1, end2);

                if (start <= end)
                {
                    ans.Add(new int[] { start, end });
                }
                if (end1 <= end2)
                    i++; // j先结束的话看i的下一个
                else
                    j++; // 同理
            }
            return ans.ToArray();
        }
    }
}
