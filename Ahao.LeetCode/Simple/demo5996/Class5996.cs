using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo5996
{
    /*
     5996. 统计数组中相等且可以被整除的数对
给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k ，请你返回满足 0 <= i < j < n ，nums[i] == nums[j] 且 (i * j) 能被 k 整除的数对 (i, j) 的 数目 。
     */
    public class Class5996
    {
        public int CountPairs(int[] nums, int k)
        {
            int res = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[i] == nums[j] && (i * j) % k == 0)
                        res++;
                }
            }

            return res;
        }
    }
}
