using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo2044
{
    /*
2044. 统计按位或能得到最大值的子集数目
给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 不同非空子集的数目 。

如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。如果选中的元素下标位置不一样，则认为两个子集 不同 。

对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。
*/
    public class Class2044
    {
        public int CountMaxOrSubsets(int[] nums)
        {
            int maxOr = 0, cnt = 0;
            for (int i = 0; i < 1 << nums.Length; i++)
            {
                int orVal = 0;
                for (int j = 0; j < nums.Length; j++)
                {
                    if (((i >> j) & 1) == 1)
                    {
                        orVal |= nums[j];
                    }
                }
                if (orVal > maxOr)
                {
                    maxOr = orVal;
                    cnt = 1;
                }
                else if (orVal == maxOr)
                {
                    cnt++;
                }
            }
            return cnt;
        }
    }
}
