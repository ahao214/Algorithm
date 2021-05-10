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

    }
}
