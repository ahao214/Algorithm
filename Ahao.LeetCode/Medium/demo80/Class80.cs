using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo80
{
    /*
     80. 删除有序数组中的重复项 II
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
     */
    public class Class80
    {
        public int RemoveDuplicates(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                return 0;
            if (nums.Length == 2)
                return nums.Length;
            var i = 0;
            var j = 1;
            var isSecond = false;
            while (j < nums.Length)
            {
                if (nums[i] != nums[j])
                {
                    isSecond = false;
                    if (i + 1 == j)
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        nums[++i] = nums[j++];
                    }
                }
                else    //ni==nj
                {
                    if (isSecond)
                        j++;
                    else
                    {
                        isSecond = true;
                        nums[++i] = nums[j++];
                    }
                }
            }
            return i + 1;
        }
    }
}
