﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 对数组进行循环移位
    /// </summary>
    public class TestRightShift
    {

        #region 蛮力法

        public static void RightShiftOne(int[] arr, int k)
        {
            if (arr == null)
            {
                Console.WriteLine("参数不合法");
            }
            int len = arr.Length;
            int tmp, i;
            while (k-- != 0)
            {
                tmp = arr[len - 1];
                for (i = len - 1; i > 0; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[0] = tmp;
            }
        }

        public static void RightShiftTwo(int[] arr, int k)
        {
            if (arr == null)
            {
                Console.WriteLine("参数不合法");
            }
            int len = arr.Length;
            k %= len;
            int i;
            while (k-- != 0)
            {
                int t = arr[len - 1];
                for (i = len - 1; i > 0; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[0] = t;
            }
        }

        #endregion


        #region 翻转法

        public static void Reverse(int[] arr, int start, int end)
        {
            while (start < end)
            {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
        }

        public static void RightShiftThree(int[] arr, int k)
        {
            if (arr == null)
            {
                Console.WriteLine("参数不合法");
            }
            int len = arr.Length;
            k %= len;
            Reverse(arr, 0, len - k - 1);
            Reverse(arr, len - k, len - 1);
            Reverse(arr, 0, len - 1);
        }


        #endregion


    }
}
