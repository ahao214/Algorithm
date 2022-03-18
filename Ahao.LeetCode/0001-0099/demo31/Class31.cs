using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo31
{
    /*
     31. 下一个排列
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。

必须 原地 修改，只允许使用额外常数空间。
     */
    public class Class31
    {
        public void NextPermutation(int[] nums)
        {
            if (nums == null || nums.Length <= 1)
                return;
            var i = nums.Length - 1;
            while (i > 0 && nums[i - 1] >= nums[i]) i--;
            if (i == 0)
            {
                Reverse(nums, 0, nums.Length - 1);
                return;
            }
            Reverse(nums, i, nums.Length - 1);
            var idx = Array.BinarySearch(nums, i, nums.Length - i, nums[i - 1] + 1);

            if (idx < 0)
                idx = ~idx;
            Swap(nums, i - 1, idx);
            Array.Sort(nums, i, nums.Length - i);
        }

        private void Reverse(int[] arr, int i, int j)
        {
            while (i < j)
            {
                Swap(arr, i++, j--);
            }
        }

        private void Swap(int[] arr, int i, int j)
        {
            //var tmp = arr[i];
            //arr[i] = arr[j];
            //arr[j] = tmp;

            arr[i] = arr[i] ^ arr[j];
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
        }

    }
}
