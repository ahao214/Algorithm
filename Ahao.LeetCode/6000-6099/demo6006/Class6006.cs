using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    /*
     6006. 拿出最少数目的魔法豆 显示英文描述 
给你一个 正 整数数组 beans ，其中每个整数表示一个袋子里装的魔法豆的数目。

请你从每个袋子中 拿出 一些豆子（也可以 不拿出），使得剩下的 非空 袋子中（即 至少 还有 一颗 魔法豆的袋子）魔法豆的数目 相等 。一旦魔法豆从袋子中取出，你不能将它放到任何其他的袋子中。

请你返回你需要拿出魔法豆的 最少数目。
     */
    public class Class6006
    {
        public long MinimumRemoval(int[] beans)
        {
            int n = beans.Length;
            Array.Sort(beans);
            long sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += beans[i];
            }
            long res = sum - n * beans[0];
            long leftSum = 0;
            for (int i = 0; i < n; i++)
            {
                leftSum += beans[i];
                sum -= beans[i];
                if (i != n - 1)
                    res = Math.Min(res, leftSum + sum - (n - i - 1) * beans[i + 1]);
            }
            return res;
        }
    }
}
