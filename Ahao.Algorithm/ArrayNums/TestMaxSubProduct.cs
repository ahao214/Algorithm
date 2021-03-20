using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出数组中的乘积最大子序列
    /// </summary>
    public class TestMaxSubProduct
    {
        public static int MaxSubProduct(int []a)
        {
            int n = a.Length;
            int[] max = new int[n];
            int[] min = new int[n];
            max[0] = a[0];
            min[0] = a[0];
            int product = max[0];
            for (int i=1;i<n;i++)
            {
                //求三者最大
                max[i] = Math.Max(a[i] > a[i] * max[i - 1] ? a[i] : a[i] * max[i - 1], a[i] * min[i - 1]);
                //求三者最小
                min[i] = Math.Min(a[i] < a[i] * max[i - 1] ? a[i] : a[i] * max[i - 1], a[i] * min[i - 1]);
                if (max[i] > product)
                    product = max[i];
            }
            return product;
        }

    }
}
