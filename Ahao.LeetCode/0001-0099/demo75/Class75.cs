using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo75
{
    /*
     75. 颜色分类
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。
     */
    public class Class75
    {
        public void SortColors(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                return;
            var p0 = 0;
            var p2 = nums.Length - 1;
            var i = 0;
            while (i <= p2)
            {
                if (nums[i] == 0)
                {
                    while (p0 < i && nums[p0] == 0)
                        p0++;
                    if (p0 < i)
                        Swap(nums, p0, i);
                    else
                        i++;
                }
                else if (nums[i] == 2)
                {
                    while (p2 > i && nums[p2] == 2)
                        p2--;
                    if (p2 > i)
                        Swap(nums, i, p2);
                    else
                        i++;
                }
                else
                {
                    i++;
                }
            }
        }

        public void SortColors2(int[] nums)
        {
            int i = 0, left = 0;
            int right = nums.Length - 1;
            while (i <= right)
            {
                int v = nums[i];
                if (v == 0)
                {
                    Swap(nums, i++, left++);
                }
                else if (v == 1)
                {
                    i++;
                }
                else
                {
                    Swap(nums, i, right--);
                }
            }
        }

        private void Swap(int[] arr, int i, int j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
}
