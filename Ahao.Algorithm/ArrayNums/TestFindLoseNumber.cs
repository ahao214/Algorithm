using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 如何知道拿走了哪个数
    /// </summary>
    public class TestFindLoseNumber
    {
        public static void FindLoseNumber(int[] array)
        {
            //求集合累加之和
            int s = 0;
            for (int i = 0; i < array.Length; i++)
            {
                s += array[i];
            }
            //求1~10000累加之和
            int s2 = 10000 * (10000 + 1) / 2;
            Console.WriteLine("丢失的数字为{0}", (s2 - s).ToString());
        }

    }
}
