using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo116
{
    /*
     116. 填充每个节点的下一个右侧节点指针
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
     */
    public class Class116
    {
        public Node Connect(Node root)
        {
            if (root == null)
            {
                return root;
            }

            var queue = new Queue<Node>();
            queue.Enqueue(root);

            while (queue.Count > 0)
            {
                var size = queue.Count;
                Node last = null;
                for (var i = 0; i < size; i++)
                {
                    var top = queue.Dequeue();
                    if (last != null)
                        last.next = top;
                    last = top;

                    if (top.left != null)
                        queue.Enqueue(top.left);
                    if (top.right != null)
                        queue.Enqueue(top.right);
                }
            }
            return root;
        }
    }

    public class Node
    {
        public int val;
        public Node left;
        public Node right;
        public Node next;

        public Node()
        {
        }

        public Node(int _val)
        {
            val = _val;
        }

        public Node(int _val, Node _left, Node _right, Node _next)
        {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }
    }
}
