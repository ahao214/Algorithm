using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo6005
{
    /*
     6005. 使数组变成交替数组的最少操作数 显示英文描述 
给你一个下标从 0 开始的数组 nums ，该数组由 n 个正整数组成。

如果满足下述条件，则数组 nums 是一个 交替数组 ：

nums[i - 2] == nums[i] ，其中 2 <= i <= n - 1 。
nums[i - 1] != nums[i] ，其中 1 <= i <= n - 1 。
在一步 操作 中，你可以选择下标 i 并将 nums[i] 更改 为 任一 正整数。

返回使数组变成交替数组的 最少操作数 。
     */
    public class Class6005
    {
        public int MinimumOperations(int[] nums)
        {
            int res = 0;
            //偶数下标最小值
            int minEven = int.MaxValue;
            //奇数下标最下值
            int minOdd = int.MaxValue;
            int n = nums.Length;
            for (int i = 0; i < n; i += 2)
            {
                minEven = Math.Min(nums[i], minEven);
            }
            for (int i = 1; i < n; i += 2)
            {
                minOdd = Math.Min(nums[i], minOdd);
            }
            for (int i = 0; i < n; i += 2)
            {
                if (nums[i] > minEven)
                    res++;
            }
            for (int i = 1; i < n; i += 2)
            {
                if (nums[i] > minOdd)
                    res++;
            }

            return res;
        }
    }
}
