using System;
using System.Collections;
using System.Collections.Generic;
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

        #region 后序遍历

        public void PostOrder()
        {
            PostOrder(root);
        }

        //后序遍历以node为根的二叉查找树-左根右的顺序
        private void PostOrder(Node node)
        {
            if (node == null)
                return;
            PostOrder(node.left);
            PostOrder(node.right);
            Console.WriteLine(node.e);
        }

        #endregion

        #region 层序遍历


        //层序遍历以node为根的二叉查找树
        public void LevelOrder()
        {
            Queue<Node> q = new Queue<Node>();
            q.Enqueue(root);
            while (q.Count != 0)
            {
                Node cur = q.Dequeue();
                Console.WriteLine(cur.e);
                if (cur.left != null)
                    q.Enqueue(cur.left);
                if (cur.right != null)
                    q.Enqueue(cur.right);
            }
        }

        #endregion

        #region 最小值和最大值

        public E Min()
        {
            if (IsEmpty)
                throw new ArgumentException("空树");
            return Min(root).e;
        }

        //返回以node为根的二叉查找树的最小值的所在的结点
        private Node Min(Node node)
        {
            if (node.left == null)
                return node;
            return Min(node.left);
        }

        public E Max()
        {
            if (IsEmpty)
                throw new ArgumentException("空树");
            return Max(root).e;
        }

        //返回以node为根的二叉查找树的最大值的所在的结点
        private Node Max(Node node)
        {
            if (node.right == null)
                return node;
            return Max(node.right);
        }

        #endregion

        #region 删除最大值和最小值

        public E RemoveMin()
        {
            E res = Min();
            root = RemoveMin(root);
            return res;
        }

        private Node RemoveMin(Node node)
        {
            if (node.left == null)
            {
                N--;
                return node.right;
            }
            node.left = RemoveMin(node.left);
            return node;
        }

        public E RemoveMax()
        {
            E res = Max();
            root = RemoveMax(root);
            return res;
        }

        private Node RemoveMax(Node node)
        {
            if (node.right == null)
            {
                N--;
                return node.left;
            }
            node.right = RemoveMax(node.right);
            return node;
        }

        #endregion

        #region 删除任意结点

        public void Remove(E e)
        {
            root = Remove(root, e);
        }

        private Node Remove(Node node, E e)
        {
            if (node == null)
                return null;
            if (e.CompareTo(node.e) < 0)
            {
                node.left = Remove(node.left, e);
                return node;
            }
            else if (e.CompareTo(node.e) > 0)
            {
                node.right = Remove(node.right, e);
                return node;
            }
            else
            {
                if (node.right == null)
                {
                    N--;
                    return node.left;
                }
                if (node.left == null)
                {
                    N--;
                    return node.right;
                }
                Node s = Min(node.right);
                s.right = RemoveMin(node.right);
                s.left = node.left;
                return s;
            }
        }

        #endregion

        #region 二叉树的高度

        public int MaxHeight()
        {
            return MaxHeight(root);
        }

        private int MaxHeight(Node node)
        {
            if (node == null)
                return 0;
            int left = MaxHeight(node.left);
            int right = MaxHeight(node.right);
            return Math.Max(left, right) + 1;
        }

        #endregion







    }
}
