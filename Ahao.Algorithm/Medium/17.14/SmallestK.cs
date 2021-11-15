using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary._17._14
{
    /// <summary>
    /// 面试题 17.14. 最小K个数
    /// </summary>
    public class SmallestK
    {
        public int[] Method(int[] arr, int k)
        {
            Array.Sort(arr);
            int[] res = new int[k];
            for (int i = 0; i < k; i++)
            {
                res[i] = arr[i];
            }
            return res;
        }
    }
}
