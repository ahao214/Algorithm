using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1089
{
    public class Class1089
    {
        /// <summary>
        /// 双指针
        /// </summary>
        /// <param name="arr"></param>
        public void DuplicateZeros(int[] arr)
        {
            int n = arr.Length;
            int top = 0;
            int i = -1;
            while (top < n)
            {
                i++;
                if (arr[i] != 0)
                {
                    top++;
                }
                else
                {
                    top += 2;
                }
            }
            int j = n - 1;
            if (top == n + 1)
            {
                arr[j] = 0;
                j--;
                i--;
            }
            while (j >= 0)
            {
                arr[j] = arr[i];
                j--;
                if (arr[i] == 0)
                {
                    arr[j] = arr[i];
                    j--;
                }
                i--;
            }
        }
    }
}
