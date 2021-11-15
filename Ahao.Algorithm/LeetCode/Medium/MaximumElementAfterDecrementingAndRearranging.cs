using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1846. 减小和重新排列数组后的最大元素
    /// </summary>
    public class MaximumElementAfterDecrementingAndRearranging
    {
        public int Method(int[] arr)
        {
            int result = 0;
            Array.Sort(arr);
            arr[0] = 1;
            int len = arr.Length;
            for (int i = 1; i < len; i++)
            {
                if (arr[i] - arr[i - 1] > 1)
                {
                    arr[i] = arr[i - 1] + 1;
                }
            }
            result = arr[len - 1];
            return result;
        }
    }
}
