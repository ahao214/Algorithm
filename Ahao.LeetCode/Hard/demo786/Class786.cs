using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo786
{
    /// <summary>
    /// 786. 第 K 个最小的素数分数
    /// </summary>
    public class Class786
    {
        public int[] KthSmallestPrimeFraction(int[] arr, int k)
        {
            int n = arr.Length;
            List<int[]> lst = new List<int[]>();
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    lst.Add(new int[] { arr[i], arr[j] });
                }
            }
            lst.Sort((x, y) => x[0] * y[1] - y[0] * x[1]);
            return lst[k - 1];
        }
    }
}
