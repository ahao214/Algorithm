using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 面试题 17.14. 最小K个数
    /// </summary>
    public class SmallestK
    {
        public int[] Method(int[] arr, int k)
        {
            int[] result = new int[k];
            Array.Sort(arr);
            for (int i = 0; i < k; i++)
            {
                result[i] = arr[i];
            }
            return result;
        }
    }
}
