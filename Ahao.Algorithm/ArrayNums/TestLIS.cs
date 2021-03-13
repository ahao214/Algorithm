using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求一个数组的最长递减子序列
    /// </summary>
    public class TestLIS
    {
        public static void LIS(int[] arr)
        {
            var len = arr.Length;
            //初始化DP数组长度
            int[] dp = new int[len];
            //连续子串长度
            int maxLength = 0;
            for (int i = len - 1; i >= 0; i--)
            {
                int max = 0;
                dp[i] = 1;
                for (int j = i + 1; j < len; j++)
                {
                    if (arr[j] < arr[i] && max < dp[j])
                    {
                        max = dp[j];
                    }
                }
                dp[i] = max + 1;
                maxLength = maxLength < dp[i] ? dp[i] : maxLength;
            }
            for (int i = 0; i < len; i++)
            {
                if (dp[i] == maxLength)
                {
                    Console.Write(arr[i] + "     ");
                    maxLength--;
                }
            }
        }
    }
}
