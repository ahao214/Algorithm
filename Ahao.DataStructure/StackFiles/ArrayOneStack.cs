using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
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

        public int Count => throw new NotImplementedException();

        public bool IsEmpty => throw new NotImplementedException();

        public void Push(E e)
        {
            throw new NotImplementedException();
        }

        public E Pop()
        {
            throw new NotImplementedException();
        }

        public E Peek()
        {
            throw new NotImplementedException();
        }
    }
}
