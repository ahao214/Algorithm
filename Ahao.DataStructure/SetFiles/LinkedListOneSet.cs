using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 无序链表实现集合
    /// </summary>
    /// <typeparam name="E"></typeparam>
    class LinkedListOneSet<E> : ISet<E>
    {
        private LinkedListOne<E> list;
        public LinkedListOneSet()
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

        public void Add(E e)
        {
            if (!list.Contains(e))
                list.AddFirst(e);
        }

        public bool Contains(E e)
        {
            return list.Contains(e);
        }

        public void Remove(E e)
        {
            list.RemoveEle(e);
        }
    }
}
