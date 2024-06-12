using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2800_2899.demo2806
{
    internal class Class2806
    {
        public int AccountBalanceAfterPurchase(int purchaseAmount)
        {
            int r = purchaseAmount % 10;
            if (r < 5)
            {
                purchaseAmount -= r;
            }
            else
            {
                purchaseAmount += 10 - r;
            }
            return 100 - purchaseAmount;
        }



        public int AccountBalanceAfterPurchase2(int purchaseAmount)
        {
            return 100 - (purchaseAmount + 5) / 10 * 10;
        }



    }
}
