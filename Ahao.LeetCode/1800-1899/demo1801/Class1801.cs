﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1801
{
    public class Class1801
    {


        public int GetNumberOfBacklogOrders(int[][] orders)
        {
            const int MOD = 1000000007;
            PriorityQueue<int[], int> buyOrders = new PriorityQueue<int[], int>();
            PriorityQueue<int[], int> sellOrders = new PriorityQueue<int[], int>();
            foreach (int[] order in orders)
            {
                int price = order[0], amount = order[1], orderType = order[2];
                if (orderType == 0)
                {
                    while (amount > 0 && sellOrders.Count > 0 && sellOrders.Peek()[0] <= price)
                    {
                        int[] sellOrder = sellOrders.Dequeue();
                        int sellAmount = Math.Min(amount, sellOrder[1]);
                        amount -= sellAmount;
                        sellOrder[1] -= sellAmount;
                        if (sellOrder[1] > 0)
                        {
                            sellOrders.Enqueue(sellOrder, sellOrder[0]);
                        }
                    }
                    if (amount > 0)
                    {
                        buyOrders.Enqueue(new int[] { price, amount }, -price);
                    }
                }
                else
                {
                    while (amount > 0 && buyOrders.Count > 0 && buyOrders.Peek()[0] >= price)
                    {
                        int[] buyOrder = buyOrders.Dequeue();
                        int buyAmount = Math.Min(amount, buyOrder[1]);
                        amount -= buyAmount;
                        buyOrder[1] -= buyAmount;
                        if (buyOrder[1] > 0)
                        {
                            buyOrders.Enqueue(buyOrder, -buyOrder[0]);
                        }
                    }
                    if (amount > 0)
                    {
                        sellOrders.Enqueue(new int[] { price, amount }, price);
                    }
                }
            }
            int total = 0;
            foreach (PriorityQueue<int[], int> pq in new PriorityQueue<int[], int>[] { buyOrders, sellOrders })
            {
                while (pq.Count > 0)
                {
                    int[] order = pq.Dequeue();
                    total = (total + order[1]) % MOD;
                }
            }
            return total;
        }
    }
}
