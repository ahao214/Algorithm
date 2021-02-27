using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出旋转数组的最小元素
    /// </summary>
    public class TestGetMin
    {
        public static int GetMin(int[] arr, int low, int high)
        {
            //如果旋转个数为0，即没有旋转，单独处理，直接返回数组头元素
            if (high < low)
            {
                return arr[0];
            }

            //只剩下一个元素一定是最小值
            if (high == low)
            {
                return arr[low];
            }

            int mid = low + ((high + low) >> 1);
            //判断是否arr[mid]为最小值
            if (arr[mid] < arr[mid - 1])
            {
                return arr[mid];
            }
            //判断是否arr[mid+1]为最小值
            else if (arr[mid + 1] < arr[mid])
            {
                return arr[mid + 1];
            }
            //最小值一定在数组左半部分
            else if (arr[high] > arr[mid])
            {
                return GetMin(arr, low, mid - 1);
            }
            //最小值一定在数组有半部分
            if (arr[mid] > arr[low])
            {
                return GetMin(arr, mid + 1, high);
            }
            else
            {
                return Math.Min(GetMin(arr, low, mid - 1), GetMin(arr, mid + 1, high));
            }
        }

        public static int GetMin(int[] arr)
        {
            if (arr == null)
            {
                Console.WriteLine("参数不合法");
                return -1;
            }
            else
            {
                return GetMin(arr, 0, arr.Length - 1);
            }
        }

    }
}
