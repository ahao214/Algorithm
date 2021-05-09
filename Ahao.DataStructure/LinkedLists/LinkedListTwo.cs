using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 链表-带头部和尾部
    /// </summary>
    class LinkedListTwo<E>
    {
        private class Node
        {
            public E e;
            public Node next;
            public Node(E e, Node next)
            {
                this.e = e;
                this.next = next;
            }

            public Node(E e)
            {
                this.e = e;
                this.next = null;
            }
            public override string ToString()
            {
                return e.ToString();
            }
        }

        //链表头部
        private Node head;
        //链表尾部
        private Node tail;
        //链表元素个数
        private int N;

        public LinkedListTwo()
        {
            head = null;
            tail = null;
            N = 0;
        }

        public int Count { get { return N; } }
        public bool IsEmpty { get { return N == 0; } }
        public void AddLast(E e)
        {
            Node node = new Node(e);
            if (IsEmpty)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail.next = node;
                tail = node;
            }
            N++;
        }

        public E RemoveFirst()
        {
            if (IsEmpty)
                throw new InvalidOperationException("链表为空");
            E e = head.e;
            head = head.next;
            N--;

            //删除后链表为空
            if (head == null)
                tail = null;
            return e;
        }

        public E GetFirst()
        {
            if (IsEmpty)
                throw new InvalidOperationException("链表为空");
            return head.e;
        }

        public override string ToString()
        {
            StringBuilder res = new StringBuilder();
            Node cur = head;
            if (cur != null)
            {
                res.Append(cur + "->");
                cur = cur.next;
            }
            res.Append("Null");
            return res.ToString();
        }

    }
}
