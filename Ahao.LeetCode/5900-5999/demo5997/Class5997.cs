using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5997
{
    /*
     5997. 找到和为给定整数的三个连续整数
给你一个整数 num ，请你返回三个连续的整数，它们的 和 为 num 。如果 num 无法被表示成三个连续整数的和，请你返回一个 空 数组
     */
    public class Class5997
    {

        public long[] SumOfThree(long num)
        {
            List<long> res = new List<long>();
            if (num % 3 == 0)
            {
                res.Add ( num / 3 - 1);
                res.Add(num / 3);
                res.Add(num / 3 + 1);
            }
            return res.ToArray();

        }
    }
}
