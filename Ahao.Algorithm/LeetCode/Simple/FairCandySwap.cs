using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 888.公平的糖果棒交换
    /// </summary>
    public class FairCandySwap
    {
        public int[] Method(int[] A, int[] B)
        {
            int sumA = 0, sumB = 0;
            int[] result = new int[2];            
            sumA = A.Sum();
            sumB = B.Sum();
            
            Array.Sort(A);
            Array.Sort(B);
            int i = 0, j = 0;
            while (i < A.Length && j < B.Length)
            {
                if (sumA - A[i] + B[j] == sumB - B[j] + A[i])
                {
                    result[0] = A[i];
                    result[1] = B[j];
                    return result;
                }
                else if (sumA - A[i] + B[j] >= sumB - B[j] + A[i])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }

            return result;

        }
    }
}
