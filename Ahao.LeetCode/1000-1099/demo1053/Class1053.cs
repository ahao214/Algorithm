using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1053
{
    public class Class1053
    {
        public int[] PrevPermOpt1(int[] arr)
        {
            int n = arr.Length;
            for (int i = n - 2; i >= 0; i--)
            {
                if (arr[i] > arr[i + 1])
                {
                    int j = n - 1;
                    while (arr[j] >= arr[i] || arr[j] == arr[j - 1])
                        j--;
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    break;
                }
            }
            return arr;
        }
    }
}
