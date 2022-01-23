using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    /*
     5991. 按符号重排数组
     给你一个下标从 0 开始的整数数组 nums ，数组长度为 偶数 ，由数目相等的正整数和负整数组成。

你需要 重排 nums 中的元素，使修改后的数组满足下述条件：

任意 连续 的两个整数 符号相反
对于符号相同的所有整数，保留 它们在 nums 中的 顺序 。
重排后数组以正整数开头。
重排元素满足上述条件后，返回修改后的数组。
     */
    public class Class5991
    {
        public int[] RearrangeArray(int[] nums)
        {
            int left = 0;
            int right = 1;
            while (left < nums.Length)
            {
                if (nums[left] < 0 && nums[right] > 0)
                {
                    Swap(nums, left, right);
                }
                else if (nums[left] > 0 && nums[right] < 0)
                {
                    left += 2;
                    right += 2;
                }
                else if (nums[left] > 0 && nums[right] > 0)
                {
                    left++;
                    right++;
                }
                else if (nums[left] < 0 && nums[right] < 0)
                {
                    right++;
                }
            }
            return nums;
        }

        private void Swap(int[] nums, int i, int j)
        {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
}
