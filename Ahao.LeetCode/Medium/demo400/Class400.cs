using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo400
{
    /// <summary>
    /// 400. 第 N 位数字
    /// </summary>
    public class Class400
    {
        //直接计算
        public int FindNthDigit(int n)
        {
            if (n < 10)
            {
                return n;
            }

            int d = 1;
            int count = 9;
            while (n > (long)d * count)
            {
                n -= d * count;
                d++;
                count *= 10;
            }

            int index = n - 1;
            int start = (int)Math.Pow(10, d - 1);
            int num = start + index / d;
            int digitIndex = index % d;
            int digit = (num / (int)(Math.Pow(10, d - digitIndex - 1))) % 10;
            return digit;
        }
    }
}
