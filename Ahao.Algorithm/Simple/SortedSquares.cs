using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 977. 有序数组的平方
    /// </summary>
    public class SortedSquares
    {
        public int[] Method(int[] A)
        {
            int[] result = new int[A.Length];
            List<int> lst = new List<int>();
            for(int i=0;i<A.Length;i++)
            {
                lst.Add(A[i] * A[i]);
            }

            result = lst.ToArray();
            Array.Sort(result);
            return result;
        }
    }
}
