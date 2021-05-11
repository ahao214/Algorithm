using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 基于二叉树实现集合
    /// </summary>
    /// <typeparam name="E"></typeparam>
    class BSTOneSet<E> : ISet<E> where E : IComparable<E>
    {
        private BSTOne<E> bst;
        public BSTOneSet()
        {
            bst = new BSTOne<E>();
        }


        public int Count
        {
            get
            {
                return bst.Count;
            }
        }

        public bool IsEmpty
        {
            get
            {
                return bst.IsEmpty;
            }
        }


        public void Add(E e)
        {
            bst.add(e);
        }

        public bool Contains(E e)
        {
            return bst.Contains(e);
        }

        public void Remove(E e)
        {
            bst.Remove(e);
        }

        public int MaxHeight()
        {
            return bst.MaxHeight();
        }

    }
}
