using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 如何进行摇摆排序
    /// </summary>
    public class TestWiggleSort
    {
        public static void WiggleSort(int[] arr)
        {
            if (arr.Length <= 1)
                return;

            for (int i = 1; i < arr.Length; i++)
            {
                if ((i % 2 == 1 && arr[i] < arr[i - 1]) || (i % 2 == 0 && arr[i] > arr[i - 1]))
                {
                    int temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;
                }
            }
        }
    }
}
