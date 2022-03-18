using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo27
{
    /*
     27. 移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
     */
    public class Class27
    {
        public int RemoveElement(int[] nums, int val)
        {
            if (nums == null || nums.Length == 0)
                return 0;
            var total = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] != val)
                {
                    nums[total] = nums[i];
                    total++;
                }
            }
            return total;
        }

        public int RemoveElement1(int[] nums, int val)
        {
            if (nums == null || nums.Length == 0)
                return 0;
            var i = 0;
            var j = nums.Length - 1;
            while (i <= j)
            {
                if (nums[i] == val)
                    nums[i] = nums[j--];
                else
                    i++;
            }
            return i;
        }
    }
}
