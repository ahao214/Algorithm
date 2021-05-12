using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 基于红黑树实现集合
    /// </summary>
    /// <typeparam name="E"></typeparam>
    class RBTOneSet<E> : ISet<E> where E : IComparable<E>
    {
        private RBTOne<E> rbt;
        public RBTOneSet()
        {
            rbt = new RBTOne<E>();
        }

        public int Count
        {
            get
            {
                return rbt.Count;
            }
        }


        public bool IsEmpty
        {
            get
            {
                return rbt.IsEmpty;
            }
        }

        public void Add(E e)
        {
            rbt.Add(e);
        }

        public bool Contains(E e)
        {
            return rbt.Contains(e);
        }

        public void Remove(E e)
        {
            Console.WriteLine("");
        }

        public int MaxHeight()
        {
            return rbt.MaxHeight();
        }
    }
}
