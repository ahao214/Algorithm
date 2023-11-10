using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.LC714
{
    public class Class714
    {

        public int MaxProfit(int[] prices, int fee)
        {
            int n = prices.Length;
            int[][] dp = new int[n][];
            for (int i = 0; i < dp.Length; i++)
            {
                dp[i] = new int[2];
            }
            dp[0][0] = 0;
            dp[0][1] = -prices[0];
            for (int i = 1; i < n; ++i)
            {
                dp[i][0] = Math.Max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
                dp[i][1] = Math.Max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            }
            return dp[n - 1][0];
        }


        public int MaxProfit2(int[] prices, int fee)
        {
            int n = prices.Length;
            int sell = 0, buy = -prices[0];
            for (int i = 1; i < n; ++i)
            {
                sell = Math.Max(sell, buy + prices[i] - fee);
                buy = Math.Max(buy, sell - prices[i]);
            }
            return sell;
        }



        public int MaxProfit3(int[] prices, int fee)
        {
            int n = prices.Length;
            int buy = prices[0] + fee;
            int profit = 0;
            for (int i = 1; i < n; ++i)
            {
                if (prices[i] + fee < buy)
                {
                    buy = prices[i] + fee;
                }
                else if (prices[i] > buy)
                {
                    profit += prices[i] - buy;
                    buy = prices[i];
                }
            }
            return profit;
        }



    }
}
