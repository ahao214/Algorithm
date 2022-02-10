using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo11
{
    /*
    11. 盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。
     */
    public class Class11
    {
        public int MaxArea(int[] height)
        {
            int maxArea = 0;
            int left = 0;
            int right = height.Length - 1;
            while (left < right)
            {
                //面积 = 短的柱子的高度 * 左右柱子之间的距离
                int nowArea = Math.Min(height[left], height[right]) * (right - left);
                maxArea = Math.Max(nowArea, maxArea);
                //移动指针
                if (height[left] < height[right])
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
            return maxArea;
        }
    }
}
