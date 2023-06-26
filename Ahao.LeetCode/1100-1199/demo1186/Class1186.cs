using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1186
{
    public class Class1186
    {

        public int MaximumSum(int[] arr)
        {
            int dp0 = arr[0], dp1 = 0, res = arr[0];
            for (int i = 1; i < arr.Length; i++)
            {
                dp1 = Math.Max(dp0, dp1 + arr[i]);
                dp0 = Math.Max(dp0, 0) + arr[i];
                res = Math.Max(res, Math.Max(dp0, dp1));
            }
            return res;
        }


    }
}
