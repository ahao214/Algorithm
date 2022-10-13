using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo769
{
    public class Class769
    {
        public int MaxChunksToSorted(int[] arr)
        {
            int m = 0, res = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                m = Math.Max(m, arr[i]);
                if (m == i)
                {
                    res++;
                }
            }
            return res;
        }
    }
}
