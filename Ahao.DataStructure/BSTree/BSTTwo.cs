using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure.BSTree
{
    class BSTTwo<Key, Value> where Key : IComparable<Key>
    {
        private class Node
        {
            public Key key;
            public Value value;
            public Node left;
            public Node right;

            public Node(Key key, Value value)
            {
                this.key = key;
                this.value = value;
                this.left = null;
                this.right = null;
            }
        }

        //根结点
        private Node root;
        //数量
        private int N;
        public BSTTwo()
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
        public void add(Key key, Value value)
        {
            if (root == null)
            {
                root = new Node(key, value);
                N++;
                return;
            }

            Node pre = null;
            Node cur = root;
            while (cur != null)
            {
                if (key.CompareTo(cur.key) == 0)
                    return;
                pre = cur;
                if (key.CompareTo(cur.key) < 0)
                    cur = cur.left;
                else
                    cur = cur.right;
            }

            cur = new Node(key, value);
            if (key.CompareTo(pre.key) < 0)
                pre.left = cur;
            else
                pre.right = cur;
            N++;

        }

        #endregion

        #region 递归添加

        //递归添加
        public void Add(Key key, Value value)
        {
            root = Add(root, key, value);
        }


        //以node为根的树中添加元素e，添加后返回根节点root
        private Node Add(Node node, Key key, Value value)
        {
            if (node == null)
            {
                N++;
                return new Node(key, value);
            }
            if (key.CompareTo(node.key) < 0)
                node.left = Add(node.left, key, value);
            else if (key.CompareTo(node.key) > 0)
                node.right = Add(node.right, key, value);
            else
                node.value = value;
            return node;
        }

        #endregion


        //返回以node为根结点的二叉查找树中key所在的结点
        private Node GetNode(Node node, Key key)
        {
            if (node == null)
                return null;
            if (key.Equals(node.key))
                return node;
            else if (key.CompareTo(node.key) < 0)
                return GetNode(node.left, key);
            else
                return GetNode(node.right, key);
        }

        public bool Contains(Key key)
        {
            return GetNode(root, key) != null;
        }

        public Value Get(Key key)
        {
            Node node = GetNode(root, key);
            if (node == null)
                throw new ArgumentException("键" + key + "不存在，无法获取对应值");
            else
                return node.value;
        }

        public void Set(Key key, Value newValue)
        {
            Node node = GetNode(root, key);
            if (node == null)
                throw new ArgumentException("键" + key + "不存在，无法修改对应值");
            else
                node.value = newValue;
        }




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
            Console.WriteLine(node.key);
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
            Console.WriteLine(node.key);
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
            Console.WriteLine(node.key);
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
                Console.WriteLine(cur.key);
                if (cur.left != null)
                    q.Enqueue(cur.left);
                if (cur.right != null)
                    q.Enqueue(cur.right);
            }
        }

        #endregion

        #region 最小值和最大值

        public Key Min()
        {
            if (IsEmpty)
                throw new ArgumentException("空树");
            return Min(root).key;
        }

        //返回以node为根的二叉查找树的最小值的所在的结点
        private Node Min(Node node)
        {
            if (node.left == null)
                return node;
            return Min(node.left);
        }

        public Key Max()
        {
            if (IsEmpty)
                throw new ArgumentException("空树");
            return Max(root).key;
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

        public Key RemoveMin()
        {
            Key res = Min();
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

        public Key RemoveMax()
        {
            Key res = Max();
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

        public void Remove(Key key)
        {
            root = Remove(root, key);
        }

        private Node Remove(Node node, Key key)
        {
            if (node == null)
                return null;
            if (key.CompareTo(node.key) < 0)
            {
                node.left = Remove(node.left, key);
                return node;
            }
            else if (key.CompareTo(node.key) > 0)
            {
                node.right = Remove(node.right, key);
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
