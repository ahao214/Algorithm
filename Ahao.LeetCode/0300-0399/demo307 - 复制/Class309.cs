using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo309
{
    public class Class309
    {

        public int maxProfit(int[] prices)
        {
            if (prices.Length == 0)
            {
                return 0;
            }

            int n = prices.Length;
            // f[i][0]: 手上持有股票的最大收益
            // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
            // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
            int[][] f = new int[n][];
            for (int i = 0; i < f.Length; i++)
            {
                f[i] = new int[3];
            }
            f[0][0] = -prices[0];
            for (int i = 1; i < n; ++i)
            {
                f[i][0] = Math.Max(f[i - 1][0], f[i - 1][2] - prices[i]);
                f[i][1] = f[i - 1][0] + prices[i];
                f[i][2] = Math.Max(f[i - 1][1], f[i - 1][2]);
            }
            return Math.Max(f[n - 1][1], f[n - 1][2]);
        }

    }
}
