﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    /*
     6024. 数组中紧跟 key 之后出现最频繁的数字
给你一个下标从 0 开始的整数数组 nums ，同时给你一个整数 key ，它在 nums 出现过。

统计 在 nums 数组中紧跟着 key 后面出现的不同整数 target 的出现次数。换言之，target 的出现次数为满足以下条件的 i 的数目：

0 <= i <= n - 2
nums[i] == key 且
nums[i + 1] == target 。
请你返回出现 最多 次数的 target 。测试数据保证出现次数最多的 target 是唯一的。
     */
    public class Class6024
    {
        public int mostFrequent1(int[] nums, int key)
        {
            int[] count = new int[1001];
            int result = 0;
            for (int i = 1; i < nums.Length; i++)
            {
                if (nums[i - 1] == key && ++count[nums[i]] > count[result])
                {
                    result = nums[i];
                }
            }
            return result;
        }
    }
}
