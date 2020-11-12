using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 922. 按奇偶排序数组 II
    /// </summary>
    public class SortArrayByParityII
    {
        public int[] Method(int[] A)
        {
            var odd = 1;
            var even = 0;
            int[] res = new int[A.Length];
            foreach (var i in A)
            {
                if (i % 2 == 1)
                {
                    res[odd] = i;
                    odd += 2;
                }
                else
                {
                    res[even] = i;
                    even += 2;
                }
            }
            return res;
        }
    }
}
