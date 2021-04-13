using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 进行骰子求和
    /// </summary>
    public class TestDicesSum
    {
        public static Dictionary<int, double> DicesSum(int n)
        {
            //初始化一个二维表格
            int[,] dp = new int[n + 1, n * 6 + 1];
            dp[1, 1] = 1;
            dp[1, 2] = 1;
            dp[1, 3] = 1;
            dp[1, 4] = 1;
            dp[1, 5] = 1;
            dp[1, 6] = 1;
            for (int i = 2; i <= n; i++)
            {
                for (int j = i; j <= i * 6; j++)
                {
                    int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0;
                    if (j - 1 > 0)
                    {
                        x1 = dp[i - i, j - 1];
                    }
                    if (j - 2 > 0)
                    {
                        x2 = dp[i - 1, j - 2];
                    }
                    if (j - 3 > 0)
                    {
                        x3 = dp[i - 1, j - 3];
                    }
                    if (j - 4 > 0)
                    {
                        x4 = dp[i - 1, j - 4];
                    }
                    if (j - 5 > 0)
                    {
                        x5 = dp[i - 1, j - 5];
                    }
                    if (j - 6 > 0)
                    {
                        x6 = dp[i - 1, j - 6];
                    }
                    dp[i, j] = x1 + x2 + x3 + x4 + x5 + x6;
                }
            }
            var dic = new Dictionary<int, double>();
            for (int i = n; i <= 6 * n; i++)
            {
                dic.Add(i, dp[n, i] / Math.Pow(6, n));
            }
            return dic;

        }
    }
}
