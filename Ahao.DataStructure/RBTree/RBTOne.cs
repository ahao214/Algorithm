using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 红黑树
    /// </summary>
    class RBTOne<E> where E : IComparable<E>
    {
        private const bool Red = true;
        private const bool Black = false;

        private class Node
        {
            public E e;
            public Node left;
            public Node right;
            public bool color;

            public Node(E e)
            {
                this.e = e;
                this.left = null;
                this.right = null;
                color = Red;
            }
        }

        //根结点
        private Node root;
        //数量
        private int N;
        public RBTOne()
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

        private bool IsRed(Node node)
        {
            if (node == null)
                return Black;
            return node.color;
        }

        //左旋转
        private Node LeftRotate(Node node)
        {
            Node x = node.right;
            node.right = x.left;
            x.left = node;
            x.color = node.color;
            node.color = Red;
            return x;
        }

        //右旋转
        private Node RightRotate(Node node)
        {
            Node x = node.left;
            node.left = x.right;
            x.right = node;
            x.color = node.color;
            node.color = Red;
            return x;
        }

    }
}
