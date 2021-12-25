using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo121
{
    /// <summary>
    /// 121. 买卖股票的最佳时机
    /// </summary>
    public class Class121
    {
        public int MaxProfit(int[] prices)
        {
            if (prices == null || prices.Length == 0)
            {
                return 0;
            }

            var buy = prices[0];
            var sell = buy;
            var max = 0;
            for (int i = 1; i < prices.Length; i++)
            {
                if (prices[i] > sell)
                {
                    sell = prices[i];
                    max = Math.Max(max, sell - buy);
                }
                else if (prices[i] < buy)
                {
                    buy = prices[i];
                    sell = buy;
                }
            }
            return max;
        }
    }
}
