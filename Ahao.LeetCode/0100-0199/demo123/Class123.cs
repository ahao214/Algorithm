using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo123
{
    public class Class123
    {
        public int MaxProfit(int[] prices)
        {
            if (prices == null || prices.Length == 0)
            {
                return 0;
            }

            int res = 0;
            //完成第一笔交易获取到的最大值 减去 再次买入股票价格，得到的最大值
            int doneOnceMinusBuyMax = -prices[0];
            //完成第一笔交易获取到的最大值
            int doneOnceMax = 0;
            int min = prices[0];
            for (int i = 1; i < prices.Length; i++)
            {
                min = Math.Min(min, prices[i]);
                res = Math.Max(res, doneOnceMinusBuyMax + prices[i]);
                doneOnceMax = Math.Max(doneOnceMax, prices[i] - min);
                doneOnceMinusBuyMax = Math.Max(doneOnceMinusBuyMax, doneOnceMax - prices[i]);
            }
            return res;
        }
    }
}
