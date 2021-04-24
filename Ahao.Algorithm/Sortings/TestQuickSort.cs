using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Sortings
{
    /// <summary>
    /// 进行快速排序
    /// </summary>
    public class TestQuickSort
    {
        public static void Sort(int [] array,int low,int high )
        {
            int i, j;
            int index;
            if (low >= high)
                return;
            i = low;
            j = high;
            index = array[i];
            while (i<j )
            {
                while (i < j && array[j] >= index)
                    j--;
                if(i<j)
                    array[i++] = array[j];
                while (i < j && array[i] < index)
                    i++;
                if (i < j)
                    array[j--] = array[i];
            }
            array[i] = index;
            Sort(array, low, i - 1);
            Sort(array, i + 1, high);
        }

        public static void QuickSort(int [] array )
        {
            Sort(array, 0, array.Length - 1);
        }
    }
}
