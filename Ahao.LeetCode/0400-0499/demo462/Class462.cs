﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo462
{
    public class Class462
    {
        /// <summary>
        /// 排序
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MinMoves2(int[] nums)
        {
            Array.Sort(nums);
            int n = nums.Length, ret = 0, x = nums[n / 2];
            for (int i = 0; i < n; i++)
            {
                ret += Math.Abs(nums[i] - x);
            }
            return ret;
        }



        Random random = new Random();
        /// <summary>
        /// 快速选择
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int MinMoves22(int[] nums)
        {
            int n = nums.Length, x = QuickSelect(nums, 0, n - 1, n / 2), ret = 0;
            for (int i = 0; i < n; ++i)
            {
                ret += Math.Abs(nums[i] - x);
            }
            return ret;
        }

        public int QuickSelect(int[] nums, int left, int right, int index)
        {
            int q = RandomPartition(nums, left, right);
            if (q == index)
            {
                return nums[q];
            }
            else
            {
                return q < index ? QuickSelect(nums, q + 1, right, index) : QuickSelect(nums, left, q - 1, index);
            }
        }

        public int RandomPartition(int[] nums, int left, int right)
        {
            int i = random.Next(right - left + 1) + left;
            Swap(nums, i, right);
            return partition(nums, left, right);
        }

        public int partition(int[] nums, int left, int right)
        {
            int x = nums[right], i = left - 1;
            for (int j = left; j < right; ++j)
            {
                if (nums[j] <= x)
                {
                    ++i;
                    Swap(nums, i, j);
                }
            }
            Swap(nums, i + 1, right);
            return i + 1;
        }

        public void Swap(int[] nums, int index1, int index2)
        {
            int temp = nums[index1];
            nums[index1] = nums[index2];
            nums[index2] = temp;
        }

    }
}
