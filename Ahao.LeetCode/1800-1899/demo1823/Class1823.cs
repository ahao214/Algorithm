using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1823
{
    public class Class1823
    {
        //模拟+队列
        public int FindTheWinner(int n, int k)
        {
            Queue<int> queue = new Queue<int>();
            for (int i = 1; i <= n; i++)
            {
                queue.Enqueue(i);
            }
            while (queue.Count > 1)
            {
                for (int i = 1; i < k; i++)
                {
                    queue.Enqueue(queue.Dequeue());
                }
                queue.Dequeue();
            }
            return queue.Peek();
        }

        //数字+递归
        public int FindTheWinner1(int n, int k)
        {
            if (n == 1)
            {
                return 1;
            }
            return (k + FindTheWinner1(n - 1, k) - 1) % n + 1;
        }


        //数字+迭代
        public int FindTheWinner2(int n, int k)
        {
            int winner = 1;
            for (int i = 2; i <= n; i++)
            {
                winner = (k + winner - 1) % i + 1;
            }
            return winner;
        }
    }
}
