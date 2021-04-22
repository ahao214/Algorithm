using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Sortings
{
    /// <summary>
    /// 进行插入排序
    /// </summary>
    public class TestInsertSort
    {
        public static void InsertSort(int[] a)
        {
            if (a != null)
            {
                for (int i = 1; i < a.Length; i++)
                {
                    int temp = a[i], j = i;
                    if (a[j - 1] > temp)
                    {
                        while (j >= 1 && a[j - 1] > temp)
                        {
                            a[j] = a[j - 1];
                            j--;
                        }
                    }
                    a[j] = temp;
                }
            }
        }
    }
}
