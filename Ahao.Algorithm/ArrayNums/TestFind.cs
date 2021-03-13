using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求解和为n的连续正数序列
    /// </summary>
    public class TestFind
    {
        //例如输入15：由于1+2+3+4+5=4+5+6=7+8=15，所以输出3个连续序列1-5、4-6、7-8
        public static int Sum(int begin, int end)
        {
            return ((end - begin + 1) * (begin + end)) / 2;
        }

        public static void Find(int number)
        {
            for (int i = 1; i < number; i++)
            {
                for (int j = i + 1; j < number; j++)
                {
                    if (Sum(i, j) == number)
                    {
                        Console.WriteLine(i + "-" + j);
                    }
                }
            }
        }

    }
}
