using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo122
{
    /// <summary>
    /// 122. 买卖股票的最佳时机 II
    /// </summary>
    public class Class122
    {
        public int MaxProfit(int[] prices)
        {
            if (prices == null || prices.Length == 0)
            {
                return 0;
            }
            var sum = 0;
            for (int i = 1; i < prices.Length; i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    sum += prices[i] - prices[i - 1];
                }
            }
            return sum;
        }
    }
}
