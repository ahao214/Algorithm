using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo258
{
    /*
   258. 各位相加
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。
*/

    public class Class258
    {
        public int AddDigits(int num)
        {
            return (num - 1) % 9 + 1;
        }


        public int AddDigits1(int num)
        {
            while (num >= 10)
            {
                int sum = 0;
                while (num > 0)
                {
                    sum += num % 10;
                    num /= 10;
                }
                num = sum;
            }
            return num;
        }
    }
}
