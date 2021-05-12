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
   /// <typeparam name="Key"></typeparam>
   /// <typeparam name="Value"></typeparam>
    class RBTTwo<Key, Value> where Key : IComparable<Key>
    {
        private const bool Red = true;
        private const bool Black = false;

        private class Node
        {
            public Key key;
            public Value value;
            public Node left;
            public Node right;
            public bool color;

            public Node(Key key, Value value)
            {
                this.key = key;
                this.value = value;
                this.left = null;
                this.right = null;
                color = Red;
            }
        }

        //根结点
        private Node root;
        //数量
        private int N;
        public RBTTwo()
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
        public void Add(Key key, Value value)
        {
            root = Add(root, key, value);
            root.color = Black;
        }

        private Node Add(Node node, Key key, Value value)
        {
            if (node == null)
            {
                N++;
                return new Node(key, value);     //默认为红结点
            }

            if (key.CompareTo(node.key) < 0)
                node.left = Add(node.left, key, value);
            else if (key.CompareTo(node.key) > 0)
                node.right = Add(node.right, key, value);
            else
                node.value = value;

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

    }
}
