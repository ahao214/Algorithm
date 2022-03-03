using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo70
{
    /*     
     70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    */
    public class Class70
    {
        public int ClimbStairs(int n)
        {
            if (n == 0)
                return 1;
            if (n == 1)
                return 1;
            var fn1 = 1;
            var fn2 = 1;
            var fn = 0;
            for (int i = 2; i <= n; i++)
            {
                fn = fn1 + fn2;
                fn1 = fn2;
                fn2 = fn;
            }
            return fn;
        }
    }
}
