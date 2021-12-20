using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo84
{
    /// <summary>
    /// 84. 柱状图中最大的矩形
    /// </summary>
    public class Class84
    {
        /*
         *超出了时间限制
         */
        public int LargestRectangleArea(int[] heights)
        {
            if (heights == null || heights.Length == 0)
            {
                return 0;
            }
            var maxArea = 0;
            for (int i = 0; i < heights.Length; i++)
            {
                var r = FindRight(i);
                var l = FindLeft(i);
                var area = heights[i] * (r - l - 1);
                maxArea = Math.Max(maxArea, area);
            }
            return maxArea;

            int FindLeft(int i)
            {
                var n = heights[i];
                for (int j = i; j >= 0; j--)
                {
                    if (heights[j] < n)
                    {
                        return j;
                    }
                }
                return -1;
            }

            int FindRight(int i)
            {
                var n = heights[i];
                for (int j = i; j < heights.Length; j++)
                {
                    if (heights[j] < n)
                    {
                        return j;
                    }
                }
                return heights.Length;
            }
        }
    }
}
