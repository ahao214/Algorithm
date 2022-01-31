using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1342
{
    /*
     1342. 将数字变成 0 的操作次数
    给你一个非负整数 num ，请你返回将它变成 0 所需要的步数。 如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。
     */
    public class Class1342
    {
        public int NumberOfSteps(int num)
        {
            int res = 0;
            while (num != 0)
            {
                if (num % 2 == 0)
                {
                    num /= 2;
                    res++;
                }
                else
                {
                    num -= 1;
                    res++;
                }
            }
            return res;
        }
    }
}
