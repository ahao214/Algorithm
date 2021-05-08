using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 数组栈
    /// </summary>
    /// <typeparam name="E"></typeparam>
    class ArrayOneStack<E> : IStack<E>
    {
        private ArrayE<E> arr;

        public ArrayOneStack(int capacity)
        {
            arr = new ArrayE<E>(capacity);
        }

        public ArrayOneStack()
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

        public void Push(E e)
        {
            arr.AddLast(e);
        }

        public E Pop()
        {
            return arr.RemoveLast();
        }

        public E Peek()
        {
            return arr.GetLast();
        }

        public override string ToString()
        {
            return "Stack:" + arr.ToString() + "top";
        }
    }
}
