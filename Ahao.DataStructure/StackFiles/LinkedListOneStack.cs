using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{

    /// <summary>
    /// 链表栈
    /// </summary>
    class LinkedListOneStack<E> : IStack<E>
    {
        private LinkedListOne<E> list;
        public LinkedListOneStack()
        {
            list = new LinkedListOne<E>();
        }
        public int Count
        {
            get
            {
                return list.Count;
            }
        }

        public bool IsEmpty
        {
            get
            {
                return list.IsEmpty;
            }
        }

        //获取
        public E Peek()
        {
            return list.GetFirst();
        }

        //删除
        public E Pop()
        {
            return list.RemoveFirst();
        }

        //入栈
        public void Push(E e)
        {
            list.AddFirst(e);
        }

        public override string ToString()
        {
            return "Stack:Top " + list.ToString();
        }

    }
}
