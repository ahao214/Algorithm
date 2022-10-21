using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo901
{
    public class StockSpanner
    {
        Stack<Tuple<int, int>> stack;
        int idx;

        public StockSpanner()
        {
            stack = new Stack<Tuple<int, int>>();
            stack.Push(new Tuple<int, int>(-1, int.MaxValue));
            idx = -1;
        }

        public int Next(int price)
        {
            idx++;
            while (price >= stack.Peek().Item2)
            {
                stack.Pop();
            }
            int ret = idx - stack.Peek().Item1;
            stack.Push(new Tuple<int, int>(idx, price));
            return ret;
        }

    }
}