using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 121.买卖股票的最佳时机
    /// </summary>
    public class MaxProfit
    {
        public int Method(int[] prices)
        {
            int buy = 0;
            int benefit = 0;
            for (int sell = 0; sell < prices.Length; sell++)
            {
                if (prices[buy] > prices[sell])
                {
                    buy = sell;
                }
                benefit = Math.Max(prices[sell] - prices[buy], benefit);
            }
            return benefit;
        }
    }
}
