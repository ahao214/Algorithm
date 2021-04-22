using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Sortings
{
    /// <summary>
    /// 进行选择排序
    /// </summary>
    public class TestSelectSort
    {
        public static void SelectSort(int[] a)
        {
            int i;
            int j;
            int temp = 0;
            int flag = 0;
            int n = a.Length;
            for (i = 0; i < n; i++)
            {
                temp = a[i];
                flag = i;
                for (j = i + 1; j < n; j++)
                {
                    if (a[j] < temp)
                    {
                        temp = a[j];
                        flag = j;
                    }
                }
                if (flag != i)
                {
                    a[flag] = a[i];
                    a[i] = temp;
                }
            }
        }


    }
}
