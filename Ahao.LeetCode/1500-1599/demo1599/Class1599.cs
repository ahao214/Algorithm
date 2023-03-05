using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1500_1599.demo1599
{
    public class Class1599
    {
        public int MinOperationsMaxProfit(int[] customers, int boardingCost, int runningCost)
        {
            int res = 0;
            int maxV = int.MinValue;
            int run = 1;
            int wait = 0, sum = 0;
            for (int i = 0; i < customers.Length; i++, run++)
            {
                wait += customers[i];
                int board = Math.Min(wait, 4);
                sum += board * boardingCost;
                sum -= runningCost;
                if (sum > maxV)
                {
                    maxV = sum;
                    res = run;
                }
                wait -= board;
            }
            while (wait > 0)
            {
                int board = Math.Min(wait, 4);
                sum += board * boardingCost;
                sum -= runningCost;
                if (sum > maxV)
                {
                    maxV = sum;
                    res = run;
                }
                wait -= board;
                run++;
            }
            return maxV <= 0 ? -1 : res;
        }

    }
}
