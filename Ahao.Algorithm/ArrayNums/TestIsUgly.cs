using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 寻找丑数
    /// </summary>
    public class TestIsUgly
    {
        //只包含因子2、3或5的数被称作丑数
        public bool IsUgly(int number)
        {
            while (number % 2 == 0)
            {
                //判断能否被2整除
                number = number / 2;
            }
            while (number % 3 == 0)
            {
                //判断能否被3整除
                number = number / 3;
            }
            while (number % 5 == 0)
            {
                //判断能否被5整除
                number = number / 5;
            }
            return number == 1;
        }

        public int FindUgly(int N)
        {
            //寻找从1开始的第N个丑数
            int count = 0;
            int number = 1;
            while (true)
            {
                if (IsUgly(number))
                {
                    //如果number是丑数计数器加1
                    count++;
                }
                if (count == N)   //找到第N个丑数，返回丑数
                {
                    return number;
                }
                else
                {
                    number++;
                }
            }
        }

        public static int ExcellenceFindUgly(int n)
        {
            //数组下标
            int index = 1;
            //满足条件的丑数数组
            int[] arr = new int[n];
            arr[0] = 1;
            int index2 = 0, index3 = 0, index5 = 0;
            while (index < n)
            {
                //求出符合条件最小的
                int min = Math.Min(Math.Min(arr[index2] * 2, arr[index3] * 3), arr[index5] * 5);
                arr[index] = min;
                while (arr[index2] * 2 <= arr[index])
                    index2++;
                while (arr[index3] * 3 <= arr[index])
                    index3++;
                while (arr[index5] * 5 <= arr[index])
                    index5++;
                index++;
            }
            //找到第n个丑数后返回丑数
            return arr[index - 1];
        }

    }
}
