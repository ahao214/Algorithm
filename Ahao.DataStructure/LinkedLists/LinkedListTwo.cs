using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 链表
    /// </summary>
    class LinkedListTwo<E>
    {
        private class Node
        {
            public E e;
            public Node next;
            public Node(E e ,Node next )
            {
                this.e = e;
                this.next = next;
            }

            public Node(E e )
            {
                this.e = e;
                this.next = null;
            }
            public override string ToString()
            {
                return e.ToString();
            }
        }



    }
}
