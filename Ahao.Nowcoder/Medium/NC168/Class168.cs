using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Medium.NC168
{
    /// <summary>
    /// NC168 盛水最多的容器
    /// </summary>
    public class Class168
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
