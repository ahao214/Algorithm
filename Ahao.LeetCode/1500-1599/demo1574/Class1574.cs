using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1500_1599.demo1574
{
    public class Class1574
    {
        public int FindLengthOfShortestSubarray(int[] arr)
        {
            int n = arr.Length, j = n - 1;
            while (j > 0 && arr[j - 1] <= arr[j])
            {
                j--;
            }
            if (j == 0)
            {
                return 0;
            }
            int res = j;
            for (int i = 0; i < n; i++)
            {
                while (j < n && arr[j] < arr[i])
                {
                    j++;
                }
                res = Math.Min(res, j - i - 1);
                if (i + 1 < n && arr[i] > arr[i + 1])
                {
                    break;
                }
            }
            return res;
        }
    }
}
