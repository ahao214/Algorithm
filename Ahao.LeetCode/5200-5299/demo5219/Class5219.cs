using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._5200_5299.demo5219
{
    /*
     5219. 每个小孩最多能分到多少糖果 显示英文描述 
题目难度Medium
给你一个 下标从 0 开始 的整数数组 candies 。数组中的每个元素表示大小为 candies[i] 的一堆糖果。你可以将每堆糖果分成任意数量的 子堆 ，但 无法 再将两堆合并到一起。

另给你一个整数 k 。你需要将这些糖果分配给 k 个小孩，使每个小孩分到 相同 数量的糖果。每个小孩可以拿走 至多一堆 糖果，有些糖果可能会不被分配。

返回每个小孩可以拿走的 最大糖果数目 。
     */
    class Class5219
    {
        public int MaximumCandies(int[] candies, long k)
        {
            int res = 0;
            long sum = candies.Sum();
            if (sum < k)
                return res;
            res = Convert.ToInt32(sum / k);
            return res;
        }
    }
}
