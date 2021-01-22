using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 989. 数组形式的整数加法
    /// </summary>
    public class AddToArrayForm
    {
        public IList<int> Method(int[] A, int K)
        {
            int len = A.Length - 1;
            int num = K;
            List<int> arr = new List<int>();
            while (len >= 0 || num > 0)
            {
                if (len >= 0)
                {
                    num += A[len];
                }
                arr.Add(num % 10);
                num /= 10;
                len--;
            }
            //数组转换
            int[] arrRev = arr.ToArray();
            //反转
            Array.Reverse(arrRev);
            return arrRev;
        }
    }
}
