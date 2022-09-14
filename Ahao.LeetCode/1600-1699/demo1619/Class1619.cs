using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1619
{
    public class Class1619
    {
        public double TrimMean(int[] arr)
        {
            int n = arr.Length;
            Array.Sort(arr);
            int partialSum = 0;
            for (int i = n / 20; i < 19 * n / 20; i++)
            {
                partialSum += arr[i];
            }
            return partialSum / (n * 0.9);
        }

    }
}
