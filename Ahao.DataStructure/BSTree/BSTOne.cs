using System;

namespace Ahao.DataStructure
{
    class BSTOne<E> where E : IComparable<E>
    {
        private class Node
        {
            public E e;
            public Node left;
            public Node righ;

            public Node(E e)
            {
                this.e = e;
                this.left = null;
                this.righ = null;
            }
        }

        //根结点
        private Node root;
        //数量
        private int N;
        public BSTOne()
        {
            root = null;
            N = 0;
        }

        //属性：数量
        public int Count
        {
            get
            {
                return N;
            }
        }

        //属性：是否为空
        public bool IsEmpty
        {
            get
            {
                return N == 0;
            }
        }


        //非递归添加
        public void add(E e)
        {
            if (root == null)
            {
                root = new Node(e);
                N++;
                return;
            }

            Node pre = null;
            Node cur = null;
            while (cur != null)
            {
                if (e.CompareTo(cur.e) == 0)
                    return;
                pre = cur;
                if (e.CompareTo(cur.e) < 0)
                    cur = cur.left;
                else
                    cur = cur.righ;
            }

            cur = new Node(e);
            if (e.CompareTo(cur.e) < 0)
                pre.left = cur;
            else
                pre.righ = cur;
            N++;

        }

    }
}
