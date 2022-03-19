using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    /*
     6012. 统计各位数字之和为偶数的整数个数
给你一个正整数 num ，请你统计并返回 小于或等于 num 且各位数字之和为 偶数 的正整数的数目。

正整数的 各位数字之和 是其所有位上的对应数字相加的结果。
     */
    public class Class6012
    {
        public int CountEven(int num)
        {
            int res = 0;
            
            for (int i = num; i > 0; i--)
            {
                int sum = 0;
                int tmp = i;
                while (tmp != 0)
                {
                    sum += tmp % 10;
                    tmp /= 10;
                }
                if (sum % 2 == 0)
                    res++;
            }

            return res;
        }
    }
}
