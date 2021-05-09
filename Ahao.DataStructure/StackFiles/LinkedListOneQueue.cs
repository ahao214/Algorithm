using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure.StackFiles
{
    /// <summary>
    /// 链表队列
    /// </summary>
    class LinkedListOneQueue<E> : IQueue<E>
    {
        private LinkedListOne<E> list;
        public LinkedListOneQueue()
        {
            list = new LinkedListOne<E>();
        }

        public int Count
        {
            get { return list.Count; }
        }


        public bool IsEmpty
        {
            get { return list.IsEmpty; }
        }

        public E Dequeue()
        {
            return list.RemoveFirst();
        }

        //时间复杂度O(n)      
        public void Enqueue(E e)
        {
            list.AddLast(e);
        }

        public E Peek()
        {
            return list.GetFirst();
        }

        public override string ToString()
        {
            return "Queue front:" + list.ToString() + "tail";
        }
    }
}
