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

        //颜色翻转
        private void FlipColor(Node node)
        {
            node.color = Red;
            node.right.color = Black;
            node.left.color = Black;
        }

        #region 添加

        //往红黑树中添加元素，递归实现
        public void Add(E e)
        {
            root = Add(root, e);
            root.color = Black;
        }

        private Node Add(Node node, E e)
        {
            if (node == null)
            {
                N++;
                return new Node(e);     //默认为红结点
            }

            if (e.CompareTo(node.e) < 0)
                node.left = Add(node.left, e);
            else if (e.CompareTo(node.e) > 0)
                node.right = Add(node.right, e);

            //如果出现右子节点是红色，而左子结点是黑色，进行左旋转
            if (IsRed(node.right) && !IsRed(node.left))
                node = LeftRotate(node);

            //如果出现连续的左子结点都为红色，进行右旋转
            if (IsRed(node.left) && IsRed(node.left.left))
                node = RightRotate(node);

            //如果出现左右子结点均为红色，进行颜色翻转
            if (IsRed(node.left) && IsRed(node.right))
                FlipColor(node);

            return node;

        }

        #endregion

    }
}
