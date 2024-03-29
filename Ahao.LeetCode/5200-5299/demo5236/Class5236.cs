﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._5200_5299.demo5236
{
    /*
      5236. 美化数组的最少删除数
     给你一个下标从 0 开始的整数数组 nums ，如果满足下述条件，则认为数组 nums 是一个 美丽数组 ：

nums.length 为偶数
对所有满足 i % 2 == 0 的下标 i ，nums[i] != nums[i + 1] 均成立
注意，空数组同样认为是美丽数组。

你可以从 nums 中删除任意数量的元素。当你删除一个元素时，被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，而左侧的元素将会保持 不变 。

返回使 nums 变为美丽数组所需删除的 最少 元素数目。
     
    输入：nums = [1,1,2,3,5]
输出：1
解释：可以删除 nums[0] 或 nums[1] ，这样得到的 nums = [1,2,3,5] 是一个美丽数组。可以证明，要想使 nums 变为美丽数组，至少需要删除 1 个元素。

     */
    public class Class5236
    {
        public int MinDeletion(int[] nums)
        {
            int res = 0;

            int cur = 0;
            int last = -1;
            foreach (var item in nums)
            {
                if (item == last && cur % 2 == 1)
                {
                    res++;
                }
                else
                {
                    cur++;
                    last = item;
                }
            }
            if (cur % 2 == 1)
                res++;

            return res;
        }


        public int MinDeletion2(int[] nums)
        {
            int ans = 0;
            int n = nums.Length;
            int i = 0;
            while (i < n)
            {
                int cur = nums[i++];
                while (i < n && nums[i] == cur)
                {
                    ans += 1;
                    i += 1;
                }
                if (i < n)
                    ++i;
                else
                    ans += 1;
            }
            return ans;
        }
    }
}
