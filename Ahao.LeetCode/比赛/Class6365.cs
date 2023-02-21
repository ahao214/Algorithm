using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6365. 将整数减少到零需要的最少操作数  

给你一个正整数 n ，你可以执行下述操作 任意 次：

n 加上或减去 2 的某个 幂
返回使 n 等于 0 需要执行的 最少 操作数。

如果 x == 2i 且其中 i >= 0 ，则数字 x 是 2 的幂。

输入：n = 39
输出：3
解释：我们可以执行下述操作：
- n 加上 20 = 1 ，得到 n = 40 。
- n 减去 23 = 8 ，得到 n = 32 。
- n 减去 25 = 32 ，得到 n = 0 。
可以证明使 n 等于 0 需要执行的最少操作数是 3 。
     */
    public class Class6365
    {
        public int MinOperations(int n)
        {
            int res = 0;

            for (int i = 0; i < 20; i++)
            {
                if ((n & 1 << i) > 0)
                {
                    if ((n & 1 << i + 1) > 0)
                    {
                        n += 1 << i;
                    }
                    res++;
                }
            }

            return res;
        }


        public int MinOperations2(int n)
        {
            return dfs(n);
        }

        private int dfs(int x)
        {
            if ((x & (x - 1)) == 0)
                return 1;
            int lb = x & -x;
            return 1 + Math.Min(dfs(x + lb), dfs(x - lb));
        }
    }
}
