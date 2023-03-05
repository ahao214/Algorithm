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



        public int MinOperationsMaxProfit2(int[] customers, int boardingCost, int runningCost)
        {
            int ans = -1;
            int maxProfit = 0;
            int totalProfit = 0;
            int operations = 0;
            int customersCount = 0;
            int n = customers.Length;
            for (int i = 0; i < n; i++)
            {
                operations++;
                customersCount += customers[i];
                int curCustomers = Math.Min(customersCount, 4);
                customersCount -= curCustomers;
                totalProfit += boardingCost * curCustomers - runningCost;
                if (totalProfit > maxProfit)
                {
                    maxProfit = totalProfit;
                    ans = operations;
                }
            }
            if (customersCount == 0)
            {
                return ans;
            }
            int profitEachTime = boardingCost * 4 - runningCost;
            if (profitEachTime <= 0)
            {
                return ans;
            }
            if (customersCount > 0)
            {
                int fullTimes = customersCount / 4;
                totalProfit += profitEachTime * fullTimes;
                operations += fullTimes;
                if (totalProfit > maxProfit)
                {
                    maxProfit = totalProfit;
                    ans = operations;
                }
                int remainingCustomers = customersCount % 4;
                int remainingProfit = boardingCost * remainingCustomers - runningCost;
                totalProfit += remainingProfit;
                if (totalProfit > maxProfit)
                {
                    maxProfit = totalProfit;
                    operations++;
                    ans++;
                }
            }
            return ans;
        }

    }
}
