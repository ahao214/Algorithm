using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1155
{
    public class Class1155
    {
        public int NumRollsToTarget(int n, int k, int target)
        {
            const int MODULO = 1000000007;
            long[][] dp = new long[n + 1][];
            for (int i = 0; i <= n; i++)
            {
                dp[i] = new long[target + 1];
            }
            dp[0][0] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= target; j++)
                {
                    int maxNum = Math.Min(k, j);
                    for (int d = 1; d <= maxNum; d++)
                    {
                        dp[i][j] += dp[i - 1][j - d];
                    }
                    dp[i][j] %= MODULO;
                }
            }
            return (int)dp[n][target];
        }


    }
}
