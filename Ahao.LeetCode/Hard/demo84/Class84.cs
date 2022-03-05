using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo84
{
    /*
     84. 柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
     */
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


        public int LargestRectangleArea2(int[] heights)
        {
            if (heights == null || heights.Length == 0)
            {
                return 0;
            }

            var stack = new Stack<Item>(heights.Length);
            var maxValue = 0;
            stack.Push(new Item(-1, -1, -1));
            for (int i = 0; i < heights.Length; i++)
            {
                if (heights[i] >= stack.Peek().Height)
                {
                    stack.Push(new Item(heights[i], i, 0));
                }
                else
                {
                    while (true)
                    {
                        var pre = stack.Pop();
                        var area = pre.Height * (pre.PreCount + i - pre.Index);
                        maxValue = Math.Max(maxValue, area);
                        if (stack.Count == 0 || stack.Peek().Height < heights[i])
                        {
                            break;
                        }
                    }
                    stack.Push(new Item(heights[i], i, i - stack.Peek().Index - 1));
                }
            }

            while (stack.Count > 0)
            {
                var pre = stack.Pop();
                var area = pre.Height * (pre.PreCount + heights.Length - pre.Index);
                maxValue = Math.Max(maxValue, area);
            }

            return maxValue;
        }

        struct Item
        {
            public readonly int Height;
            public readonly int Index;
            public readonly int PreCount;
            public Item(int height, int index, int preCount)
            {
                this.Height = height;
                this.Index = index;
                this.PreCount = preCount;
            }
        }




        public int LargestRectangleArea3(int[] heights)
        {
            Stack<int> st = new Stack<int>();
            int area = 0;

            int[] exHeights = new int[heights.Length + 2];
            for (int i = 1; i < exHeights.Length - 1; i++)
            {
                exHeights[i] = heights[i - 1];
            }

            st.Push(0);

            for (int i = 1; i < exHeights.Length; i++)
            {
                while (exHeights[i] < exHeights[st.Peek()])
                {
                    // i前的，最高的柱子
                    int mid = st.Pop();
                    // mid能延伸的距离
                    int distance = i - st.Peek() - 1;
                    int h = exHeights[mid];
                    area = Math.Max(area, h * distance);
                }
                st.Push(i);
            }
            return area;
        }

    }
}
