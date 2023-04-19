using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1043
{
    public class Class1043
    {
        public int MaxSumAfterPartitioning(int[] arr, int k)
        {
            int n = arr.Length;
            int[] d = new int[n + 1];
            for (int i = 1; i <= n; i++)
            {
                int maxValue = arr[i - 1];
                for (int j = i - 1; j >= 0 && j >= i - k; j--)
                {
                    d[i] = Math.Max(d[i], d[j] + maxValue * (i - j));
                    if (j > 0)
                    {
                        maxValue = Math.Max(maxValue, arr[j - 1]);
                    }
                }
            }
            return d[n];
        }


    }
}
