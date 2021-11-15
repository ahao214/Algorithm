using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 剑指 Offer II 069. 山峰数组的顶部
    /// </summary>
    public class PeakIndexInMountainArrays
    {
        public int Method(int[] arr)
        {
            int res = -1;
            if (arr == null || arr.Length == 0)
            {
                return res;
            }
            for (int i = 0; i < arr.Length - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    res = i;
                    break;
                }
            }
            return res;
        }
    }
}
