using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.Sortings
{
    /// <summary>
    /// 希尔排序
    /// </summary>
    public class TestShellSort
    {
        public static void ShellSort(int[] arr)
        {
            int len = arr.Length;
            int i, j;
            int h;
            int temp;
            for (h = len / 2; h > 0; h = h / 2)
            {
                for (i = h; i < len; i++)
                {
                    temp = arr[i];
                    for (j = i - h; j >= 0; j -= h)
                    {
                        if (temp < arr[j])
                        {
                            arr[j + h] = arr[j];
                        }
                        else
                        {
                            break;
                        }
                    }
                    arr[j + h] = temp;
                }
            }
        }

    }
}
