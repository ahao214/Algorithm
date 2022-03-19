using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo747
{
    /// <summary>
    /// 747. 至少是其他数字两倍的最大数
    /// 给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
    ///    请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。
    /// </summary>
    public class Class747
    {
        public int DominantIndex(int[] nums)
        {
            int size = nums.Length;
            if (size == 1)
            {
                return 0;
            }

            int maxValue = nums.Max();            
            int halfValue = maxValue / 2;
            int index = -1;
            for (int i = 0; i < size; i++)
            {
                if (maxValue == nums[i])
                    index = i;
            }            
            for (int i = 0; i < size; i++)
            {
                if (nums[i] > halfValue && nums[i] != maxValue)
                {
                    return -1;
                }
            }
            return index;
        }
    }
}
