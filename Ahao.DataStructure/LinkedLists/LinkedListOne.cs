using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 链表
    /// </summary>
    /// <typeparam name="E"></typeparam>
    class LinkedListOne<E>
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
        //链表个数
        private int N;
        public LinkedListOne()
        {
            head = null;
            N = 0;
        }

        public int Count
        {
            get { return N; }
        }

        public bool IsEmpty
        {
            get { return N == 0; }
        }

        #region 添加

        public void Add(int index, E e)
        {
            if (index < 0 || index > N)
                throw new ArgumentException("非法索引");

            if (index == 0)
            {
                //Node node = new Node(e);
                //node.next = head;
                //head = node;
                //上面三句代码可以用下面的一句代码代替
                head = new Node(e, head);
            }
            else
            {
                Node pre = head;
                //找到要插入的元素的前一个元素所在的位置
                for (int i = 0; i < index - 1; i++)
                    pre = pre.next;
                //Node node = new Node(e);
                //node.next = pre.next;
                //pre.next = node;

                //上面三句代码可以用下面的一句代码代替
                pre.next = new Node(e, pre.next);

            }
            N++;
        }


        public void AddFirst(E e)
        {
            Add(0, e);
        }

        public void AddLast(E e)
        {
            Add(N, e);
        }

        #endregion

        #region 查找

        public E Get(int index)
        {
            if (index < 0 || index >= N)
                throw new ArgumentException("非法索引");

            Node cur = head;
            for (int i = 0; i < index; i++)
                cur = cur.next;

            return cur.e;
        }

        public E GetFirst()
        {
            return Get(0);
        }

        public E GetLast()
        {
            return Get(N - 1);
        }

        #endregion

        #region 修改

        public void Set(int index, E newE)
        {
            if (index < 0 || index >= N)
                throw new ArgumentException("非法索引");

            Node cur = head;
            for (int i = 0; i < index; i++)
                cur = cur.next;
            cur.e = newE;
        }

        #endregion

        #region 查找元素是否存在

        public bool Contains(E e)
        {
            Node cur = head;
            while (cur != null)
            {
                if (cur.e.Equals(e))
                    return true;
                cur = cur.next;
            }
            return false;
        }

        #endregion

        #region 打印

        public override string ToString()
        {
            StringBuilder res = new StringBuilder();
            Node cur = head;
            while (cur != null)
            {
                res.Append(cur + "->");
                cur = cur.next;
            }
            res.Append("Null");
            return res.ToString();
        }

        #endregion

        #region 删除

        //根据索引删除元素
        public E RemoveIndex(int index)
        {
            if (index < 0 || index >= N)
                throw new ArgumentException("非法索引");

            if (index == 0)
            {
                Node delNode = head;
                head = head.next;
                N--;
                return delNode.e;
            }
            else
            {
                Node pre = head;
                for (int i = 0; i < index; i++)
                    pre = pre.next;

                Node delNode = pre.next;
                pre.next = delNode.next;
                N--;
                return delNode.e;
            }
        }

        public E RemoveFirst()
        {
            return RemoveIndex(0);
        }

        public E RemoveLast()
        {
            return RemoveIndex(N - 1);
        }

        //删除链表中指定的结点
        public void RemoveEle(E e)
        {
            if (head == null)
                return;

            if (head.e.Equals(e))
            {
                head = head.next;
                N--;
            }
            else
            {
                Node cur = head;
                Node pre = null;
                while (cur != null)
                {
                    if (cur.e.Equals(e))
                        break;

                    pre = cur;
                    cur = cur.next;
                }
                if (cur != null)
                {
                    pre.next = pre.next.next;
                    N--;
                }
            }

        }

        #endregion


    }
}
