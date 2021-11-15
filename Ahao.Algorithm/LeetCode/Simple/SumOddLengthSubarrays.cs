using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1588. 所有奇数长度子数组的和
    /// </summary>
   public  class SumOddLengthSubarrays
    {
        public int Method(int [] arr)
        {
            int sum = 0;
            for(int w =1;w<=arr .Length;w+=2)
            {
                for(int L=0,R=L+w;R<=arr.Length;R++,L++)
                {
                    for(int i=L;i<R;i++)
                    {
                        sum += arr[i];
                    }
                }
            }

            return sum;
        }
    }
}
