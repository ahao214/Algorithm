using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo6015
{
    /*
     6015. 统计可以被 K 整除的下标对数目
给你一个下标从 0 开始、长度为 n 的整数数组 nums 和一个整数 k ，返回满足下述条件的下标对 (i, j) 的数目：

0 <= i < j <= n - 1 且
nums[i] * nums[j] 能被 k 整除。
     */
    public class Class6015
    {
        public long CoutPairs(int[] nums, int k)
        {
            int res = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    long m = nums[i];
                    long n = nums[j];
                    if ((n * m) % k == 0)
                        res++;
                }
            }

            return res;
        }
    }
}
