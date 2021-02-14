using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Web.Hosting;
using System.Web.UI;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 实现LRU缓存方案
    /// </summary>
    public class TestLRU
    {
        private int cacheSize;
        private LinkedList<int> queue = new LinkedList<int>();
        private HashSet<int> hashSet = new HashSet<int>();

        public TestLRU(int cacheSize)
        {
            this.cacheSize = cacheSize;
        }

        //判断缓存队列是否已满
        private bool IsQueueFull()
        {
            return queue.Count() == cacheSize;
        }

        //把页号为pageNum的也缓存到队列中，同时也添加到Hash表中
        private void enqueue(int pageNum)
        {
            //如果队列满了，需要删除队尾的缓存的页
            if (IsQueueFull())
            {
                hashSet.Remove(queue.Last());
                queue.RemoveLast();
            }

            queue.AddFirst(pageNum);
            //把新缓存的结点同时添加到Hash表中
            hashSet.Add(pageNum);
        }


        /// <summary>
        /// 当访问某一个page的时候回调用这个函数，对于访问的page有两种情况
        /// 1、如果page在缓存队列中，直接把这个结点移动到队首
        /// 2、如果page不在缓存队列中，把这个page缓存到队首
        /// </summary>
        /// <param name="pageNum"></param>
        public void AccessPage(int pageNum)
        {
            //page不在缓存队列中，把它缓存到队首
            if (!hashSet.Contains(pageNum))
            {
                enqueue(pageNum);
            }
            //page已经在缓存队列中了，移动到队首
            else if (pageNum != queue.First())
            {
                queue.Remove(pageNum);
                queue.AddFirst(pageNum);
            }
        }

        public void PrintQueue()
        {
            while (queue.Count > 0)
            {
                Console.Write(queue.First() + "");
                queue.RemoveFirst();
            }
        }
    }
}
