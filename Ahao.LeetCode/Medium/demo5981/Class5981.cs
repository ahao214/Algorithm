﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5981
{
    /*
     5981. 分组得分最高的所有下标
     给你一个下标从 0 开始的二进制数组 nums ，数组长度为 n 。nums 可以按下标 i（ 0 <= i <= n ）拆分成两个数组（可能为空）：numsleft 和 numsright 。

    numsleft 包含 nums 中从下标 0 到 i - 1 的所有元素（包括 0 和 i - 1 ），而 numsright 包含 nums 中从下标 i 到 n - 1 的所有元素（包括 i 和 n - 1 ）。
    如果 i == 0 ，numsleft 为 空 ，而 numsright 将包含 nums 中的所有元素。
    如果 i == n ，numsleft 将包含 nums 中的所有元素，而 numsright 为 空 。
    下标 i 的 分组得分 为 numsleft 中 0 的个数和 numsright 中 1 的个数之 和 。
    返回 分组得分 最高 的 所有不同下标 。你可以按 任意顺序 返回答案。
     */
    public class Class5981
    {
        public IList<int> MaxScoreIndices(int[] nums)
        {
            int sum = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                sum += nums[i];
            }
            List<int> res = new List<int>();
            int ans = sum;
            int tmp = sum;
            res.Add(0);
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] == 1)
                {
                    tmp--;
                }
                else
                {
                    tmp++;
                }
                if (tmp > ans)
                {
                    ans = tmp;
                    res.Clear();
                }
                if (tmp == ans)
                {
                    res.Add(i + 1);
                }
            }
            return res.ToArray();

        }
    }
}
