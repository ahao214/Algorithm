using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 11.盛做多水的容器
    /// </summary>
    public class MaxArea
    {
        public int Method(int[] height)
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
