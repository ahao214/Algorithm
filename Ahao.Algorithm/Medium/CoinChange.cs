using Microsoft.Win32.SafeHandles;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 322. 零钱兑换
    /// </summary>
    public class CoinChange
    {
        public int Method(int[] coins, int amount)
        {
            int[] dp = new int[amount + 1];
            for (int i = 0; i < amount + 1; i++)
            {
                dp[i] = amount + 1;
            }

            dp[0] = 0;
            for (int i = 1; i <= amount; i++)
            {
                for (int j = 0; j < coins.Length; j++)
                {
                    if (coins[j] <= i)
                    {
                        dp[i] = Math.Min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
            return dp[amount] > amount ? -1 : dp[amount];
        }

    }
}
