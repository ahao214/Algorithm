using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 在数组中找出前K大的值
    /// </summary>
    public class TestFindTopK
    {
        public static void FindTopK(int[] arr)
        {
            if (arr == null || arr.Length < 1)
            {
                Console.WriteLine("参数不合法");
                return;
            }
            int one, two, three;
            one = two = three = int.MinValue;
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] > one)
                {
                    three = two;
                    two = one;
                    one = arr[i];
                }
                else if (arr[i] > two && arr[i] != one)
                {
                    three = two;
                    two = arr[i];
                }
                else if (arr[i] > three && arr[i] != two)
                {
                    three = arr[i];
                }
            }
            Console.WriteLine("前三名分别为：" + one + "," + two + "," + three);

        }


    }
}
