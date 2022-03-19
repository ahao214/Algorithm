using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1588
{
    /*
     1588. 所有奇数长度子数组的和
给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

子数组 定义为原数组中的一个连续子序列。

请你返回 arr 中 所有奇数长度子数组的和 。
     */
    public class Class1588
    {
        public int SumOddLengthSubarrays(int[] arr)
        {
            int res = 0;
            for (int w = 1; w <= arr.Length; w += 2)
            {
                for (int L = 0, R = L + w; R <= arr.Length; R++, L++)
                {
                    for (int i = L; i < R; i++)
                    {
                        res += arr[i];
                    }
                }
            }
            return res;
        }
    }
}
