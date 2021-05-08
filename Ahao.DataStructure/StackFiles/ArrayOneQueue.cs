using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 数组队列
    /// </summary>
    /// <typeparam name="E"></typeparam>
    class ArrayOneQueue<E> : IQueue<E>
    {
        private ArrayE<E> arr;
        public ArrayOneQueue(int capacity)
        {
            arr = new ArrayE<E>(capacity);
        }

        public ArrayOneQueue()
        {
            arr = new ArrayE<E>();
        }


        public int Count
        {
            get
            {
                return arr.Count;
            }
        }

        public bool IsEmpty
        {
            get
            {
                return arr.IsEmpty;
            }
        }
        //出队
        public E Dequeue()
        {
            return arr.RemoveFirst();
        }
        //入队
        public void Enqueue(E e)
        {
            arr.AddLast(e);
        }

        public E Peek()
        {
            return arr.GetFirst();
        }

        public override string ToString()
        {
            return "Queue:front " + arr.ToString() + " tail";
        }
    }
}
