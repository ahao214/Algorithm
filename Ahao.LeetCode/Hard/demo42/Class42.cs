using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo42
{
    /*
     42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 
     */
    public class Class42
    {
        public int Trap(int[] height)
        {
            if (height == null || height.Length <= 2)
                return 0;
            var left = 0;
            var right = height.Length - 1;
            var sum = 0;
            while (left < right)
            {
                var leftHeight = height[left];
                var rightHeight = height[right];
                if (leftHeight < rightHeight)
                {
                    var i = left + 1;
                    while (leftHeight > height[i])
                    {
                        sum += leftHeight - height[i];
                        i++;
                    }
                    left = i;
                }
                else
                {
                    var i = right - 1;
                    while (rightHeight > height[i])
                    {
                        sum += rightHeight - height[i];
                        i--;
                    }
                    right = i;
                }
            }
            return sum;
        }
    }
}
