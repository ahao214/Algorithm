using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 1014.最佳观光组合
    /// </summary>
    public class MaxScoreSightseeingPair
    {

        public int Method(int[] A)
        {
            int left = A[0];
            int res = int.MinValue;
            for (int j = 1; j < A.Length; j++)
            {
                res = Math.Max(res, left + A[j] - j);
                left = Math.Max(left, A[j] + j);
            }
            return res;
        }
    }


}
