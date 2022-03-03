using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo66
{
    /*
     66. 加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
     */
    public class Class66
    {
        public int[] PlusOne(int[] digits)
        {
            if (digits.All(t => t == 9))
            {
                var result = new int[digits.Length + 1];
                result[0] = 1;
                return result;
            }
            else
            {
                var result = (int[])digits.Clone();
                var i = result.Length - 1;
                result[i]++;
                while (result[i] == 10)
                {
                    result[i--] = 0;
                    result[i]++;
                }
                return result;
            }
        }
    }
}
