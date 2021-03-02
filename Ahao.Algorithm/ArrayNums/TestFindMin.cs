using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求数组中绝对值最小的数
    /// </summary>
    public class TestFindMin
    {
        public static int FindMin(int[] arr)
        {
            if (arr == null || arr.Length <= 0)
            {
                Console.WriteLine("参数不合法");
                return 0;
            }
            int min = int.MaxValue;
            for (int i = 0; i < arr.Length; i++)
            {
                if (Math.Abs(arr[i]) < Math.Abs(min))
                    min = arr[i];
            }
            return min;
        }


        public static int FindMinT(int[] arr)
        {
            if (arr == null || arr.Length <= 0)
            {
                Console.WriteLine("参数不合法");
                return 0;
            }

            int len = arr.Length;
            //数中没有负数
            if (arr[0] >= 0)
                return arr[0];
            //数组中没有正数
            if (arr[len - 1] <= 0)
                return arr[len - 1];

            int mid = 0;
            int begin = 0;
            int end = len - 1;
            int absMin = 0;
            //数组中既有正数也有负数
            while (true)
            {
                mid = begin + (end - begin) / 2;
                //如果等于0，那么就是绝对值最小的数
                if (arr[mid] == 0)
                {
                    return 0;
                }
                //如果值大于0，正负数的分界点在左侧
                else if (arr[mid] > 0)
                {
                    //继续在数组的左半部分查找
                    if (arr[mid - 1] > 0)
                        end = mid - 1;
                    else if (arr[mid - 1] == 0)
                        return 0;
                    //找到正负数的分界点
                    else
                        break;
                }
                //如果小于0，在数组的有半部分查找
                else
                {
                    //在数组有半部分继续查找
                    if (arr[mid + 1] < 0)
                        begin = mid + 1;
                    else if (arr[mid + 1] == 0)
                        return 0;
                    //找打正负数的分界点
                    else
                        break;
                }

            }

            //获取正负数分界点出绝对值最小的值
            if (arr[mid] > 0)
            {
                if (arr[mid] < Math.Abs(arr[mid - 1]))
                    absMin = arr[mid];
                else
                    absMin = arr[mid - 1];                   
            }
            else
            {
                if (Math.Abs(arr[mid]) < arr[mid + 1])
                    absMin = arr[mid];
                else
                    absMin = arr[mid + 1];
            }
            return absMin;
        }

    }
}
