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



    }
}
