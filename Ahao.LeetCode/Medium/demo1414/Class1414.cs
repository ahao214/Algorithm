using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1414
{
    /*
    1414. 和为 K 的最少斐波那契数字数目
    给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

    斐波那契数字定义为：

    F1 = 1
    F2 = 1
    Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
    数据保证对于给定的 k ，一定能找到可行解。
     */
    public class Class1414
    {
        public int FindMinFibonacciNumbers(int k)
        {
            if (k == 0) return 0;
            int f1 = 1;
            int f2 = 1;
            //找距离K最近的数字
            while (f2 <= k)
            {
                int f3 = f1 + f2;
                f1 = f2;
                f2 = f3;
            }
            return FindMinFibonacciNumbers(k - f1) + 1;
        }

        public int FindMinFibonacciNumbers1(int k)
        {
            IList<int> f = new List<int>();
            f.Add(1);
            int a = 1, b = 1;
            while (a + b <= k)
            {
                int c = a + b;
                f.Add(c);
                a = b;
                b = c;
            }
            int ans = 0;
            for (int i = f.Count - 1; i >= 0 && k > 0; i--)
            {
                int num = f[i];
                if (k >= num)
                {
                    k -= num;
                    ans++;
                }
            }
            return ans;
        }

    }
}
