using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求数组连续最大和
    /// </summary>
    public class TestMaxSubArray
    {
        #region 蛮力法

        public static int MaxSubArray(int[] arr)
        {
            if (arr == null || arr.Length <= 0)
            {
                Console.WriteLine("参数不合法");
                return -1;
            }

            int thisSum = 0, maxSum = 0, i, j, k;
            for (i = 0; i < arr.Length; i++)
            {
                for (j = i; j < arr.Length; j++)
                {
                    thisSum = 0;
                    for (k = i; k < j; k++)
                    {
                        thisSum += arr[k];
                    }
                    if (thisSum > maxSum)
                        maxSum = thisSum;
                }
            }
            return maxSum;
        }

        #endregion




    }
}
