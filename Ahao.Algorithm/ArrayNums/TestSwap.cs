using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 实现数组旋转
    /// </summary>
    public class TestSwap
    {
        public static void Swap(int[] arr, int low, int high)
        {
            //交换数组low到high的内容
            for (; low < high; low++, high--)
            {
                int tmp = arr[low];
                arr[low] = arr[high];
                arr[high] = tmp;
            }
        }

        public static void rotatearr(int[] arr, int div)
        {
            if (arr == null || div < 0 || div >= arr.Length)
            {
                Console.WriteLine("参数不合法");
                return;
            }

            //不需要旋转
            if (div == 0 || div == arr.Length - 1)
                return;
            //交换第一个子数组的内容
            Swap(arr, 0, div);
            //交换第二个子数组的内容
            Swap(arr, div + 1, arr.Length - 1);
            //交换整个数组的元素
            Swap(arr, 0, arr.Length - 1);
        }

    }
}
