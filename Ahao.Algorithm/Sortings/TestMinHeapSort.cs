using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Sortings
{
    /// <summary>
    /// 堆排序
    /// </summary>
    public class TestMinHeapSort
    {
        public static void adjustMinHeap(int[] arr, int pos, int len)
        {
            int temp;
            int child;
            for (temp = arr[pos]; 2 * pos + 1 <= len; pos = child)
            {
                child = 2 * pos + 1;
                if (child < len && arr[child] > arr[child + 1])
                    child++;
                if (arr[child] < temp)
                    arr[pos] = arr[child];
                else
                    break;
            }
            arr[pos] = temp;
        }

        public static void MinHeapSort(int[] arr)
        {
            int i;
            int len = arr.Length;
            for (i = len / 2 - 1; i >= 0; i--)
                adjustMinHeap(arr, i, len - 1);
            for (i = len - 1; i >= 0; i--)
            {
                int tmp = arr[0];
                arr[0] = arr[i];
                arr[i] = tmp;
                adjustMinHeap(arr, 0, i - 1);
            }
        }
    }
}
