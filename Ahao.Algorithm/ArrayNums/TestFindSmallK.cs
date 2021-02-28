using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出数组中第K小的数
    /// </summary>
    public class TestFindSmallK
    {
        /// <summary>
        /// 方法功能：在数组arr中找出第K小的值
        /// 输入参数：arr为整数数组，low为数组起始下标，high为数组右边界的下标，k为整数
        /// </summary>
        /// <param name="arr"></param>
        /// <param name="low"></param>
        /// <param name="high"></param>
        public static int FindSmallK(int[] arr, int low, int high, int k)
        {
            int i, j;
            int splitElem;
            i = low;
            j = high;
            splitElem = arr[i];
            //把小于等于splitElem的数放到数组中splitElem的左边，大于splitElem的值放到右边
            while (i < j)
            {
                while (i < j && arr[j] >= splitElem)
                {
                    j--;
                }
                if (i < j)
                {
                    arr[i++] = arr[j];
                }
                while (i < j && arr[i] <= splitElem)
                {
                    i++;
                }
                if (i < j)
                {
                    arr[j--] = arr[i];
                }
            }
            arr[i] = splitElem;
            int subArrayIndex = i - low;
            //如果splitElem在arr[low~high]所在的位置恰好为k-1，那么它就是第k小的元素
            if (subArrayIndex == k - 1)
            {
                return arr[i];
            }
            //如果splitElem在arr[low~high]所在的位置大于k-1，那么只需在arr[low~i-1]中找第k小的元素
            else if (subArrayIndex > k - 1)
            {
                return FindSmallK(arr, low, i - 1, k);
            }
            //在arr[i+1~high]中找
            else
            {
                return FindSmallK(arr, i + 1, high, k - (i - low) - 1);
            }
        }
    }
}
