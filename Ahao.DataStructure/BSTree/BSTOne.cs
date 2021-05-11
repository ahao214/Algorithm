using System;
using System.Runtime.InteropServices.WindowsRuntime;

namespace Ahao.DataStructure
{
    class BSTOne<E> where E : IComparable<E>
    {
        private class Node
        {
            public E e;
            public Node left;
            public Node right;

            public Node(E e)
            {
                this.e = e;
                this.left = null;
                this.right = null;
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

        #region 非递归添加

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
            Node cur = root;
            while (cur != null)
            {
                if (e.CompareTo(cur.e) == 0)
                    return;
                pre = cur;
                if (e.CompareTo(cur.e) < 0)
                    cur = cur.left;
                else
                    cur = cur.right;
            }

            cur = new Node(e);
            if (e.CompareTo(pre.e) < 0)
                pre.left = cur;
            else 
                pre.right = cur;
            N++;

        }

        #endregion

        #region 递归添加

        //递归添加
        public void Add(E e)
        {
            root = Add(root, e);
        }


        //以node为根的树中添加元素e，添加后返回根节点root
        private Node Add(Node node, E e)
        {
            if (node == null)
            {
                N++;
                return new Node(e);
            }
            if (e.CompareTo(node.e) < 0)
                node.left = Add(node.left, e);
            else if (e.CompareTo(node.e) > 0)
                node.right = Add(node.right, e);

            return node;
        }

        #endregion

        #region 查找元素

        public bool Contains(E e)
        {
            return Contains(e);
        }

        private bool Contains(Node node, E e)
        {
            if (node == null)
                return false;
            if (e.CompareTo(node.e) == 0)
                return true;
            else if (e.CompareTo(node.e) < 0)
                return Contains(node.left, e);
            else
                return Contains(node.right, e);
        }


        #endregion

        #region 前序遍历

        public void PreOrder()
        {
            PreOrder(root);
        }

        //前序遍历以node为根的二叉查找树-根左右
        private void PreOrder(Node node)
        {
            if (node == null)
                return;
            Console.WriteLine(node.e);
            PreOrder(node.left);
            PreOrder(node.right);
        }

        #endregion

        #region 中序遍历

        public void InOrder()
        {
            InOrder(root);
        }

        //中序遍历以node为根的二叉查找树-左根右的顺序
        private void InOrder(Node node)
        {
            if (node == null)
                return;
            InOrder(node.left);
            Console.WriteLine(node.e);
            InOrder(node.right);
        }

        #endregion



    }
}
