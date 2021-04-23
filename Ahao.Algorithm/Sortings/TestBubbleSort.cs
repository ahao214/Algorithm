using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Sortings
{
    /// <summary>
    /// 冒泡排序
    /// </summary>
    public class TestBubbleSort
    {
        public static void BubbleSort(int[] arr)
        {
            int i, j;
            int len = arr.Length;
            int tmp;
            for (i = 0; i < arr.Length; i++)
            {
                for (j = len - 1; j > i; --j)
                {
                    if (arr[j] < arr[j - 1])
                    {
                        tmp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = tmp;
                    }
                }
            }
        }

    }
}
