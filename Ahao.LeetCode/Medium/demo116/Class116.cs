using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo116
{
    /// <summary>
    /// 116. 填充每个节点的下一个右侧节点指针
    /// </summary>
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

        public Node() { }

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
