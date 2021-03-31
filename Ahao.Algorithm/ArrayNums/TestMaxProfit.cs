using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 计算买股票的最佳时间
    /// </summary>
    public class TestMaxProfit
    {
        public static int MaxProfit(int[] prices)
        {
            int res = 0;
            if (prices.Length < 2)
            {
                return res;
            }
            int lowest = prices[0];
            for (int i = 1; i < prices.Length; i++)
            {
                int cur = prices[i];
                res = Math.Max(res, cur - lowest);
                lowest = Math.Min(lowest, cur);
            }
            return res;
        }

    }
}
