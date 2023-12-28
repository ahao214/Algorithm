using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2706
{
    internal class Class2706
    {

        public int BuyChoco(int[] prices, int money)
        {
            Array.Sort(prices);
            int sum = prices[0] + prices[1];
            if (sum <= money)
                return money - sum;
            return money;
        }

        public int BuyChoco2(int[] prices, int money)
        {
            int fi = int.MaxValue, se = int.MaxValue;
            foreach (int price in prices)
            {
                if (price < fi)
                {
                    se = fi;
                    fi = price;
                }
                else if (price < se)
                {
                    se = price;
                }
            }
            return money < fi + se ? money : money - fi - se;
        }


    }
}
