using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求解数组分为和相等的m份后m最大值问题
    /// </summary>
    public class TestGetMMax
    {
        public static void GetMax(int[] arr)
        {
            int sum = arr.Sum();
            int n = arr.Length;
            int[] temp = new int[n];

            for (int m = n; m > 1; m--)
            {
                if (sum % m != 0)
                {
                    continue;
                }
                for (int j = 0; j < n; j++)
                {
                    temp[j] = 0;
                }
                if (IsMatch(arr, m, sum / m, temp, sum / m, 1))
                {
                    Console.WriteLine("The Max m is :" + m);
                    break;
                }
            }
        }


        public static bool IsMatch(int[] arr, int m, int groupSum, int[] temp, int total, int groupID)
        {
            int n = arr.Length;
            if (total < 0)
            {
                //加上当前元素后数组元素的和过大
                return false;
            }
            if (total == 0)
            {
                groupID++;
                total = groupSum;
                if (groupID == m + 1)
                {
                    return true;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (temp[i] != 0)
                {
                    continue;
                }
                temp[i] = groupID;
                if (IsMatch(arr, m, groupSum, temp, total - arr[i], groupID))
                {
                    return true;
                }
                temp[i] = 0;
            }
            return false;
        }

    }
}
