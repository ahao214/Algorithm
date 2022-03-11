using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo117
{
    /*
     117. 填充每个节点的下一个右侧节点指针 II
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
     */
    public class Class117
    {
        public Node Connect(Node root)
        {
            var pd = new Node() { next = root };
            while (pd.next != null)
            {
                var pnode = pd.next;
                var dummy = new Node();
                var tail = dummy;
                while (pnode != null)
                {
                    if (pnode.left != null)
                        tail = tail.next = pnode.left;
                    if (pnode.right != null)
                        tail = tail.next = pnode.right;
                    pnode = pnode.next;
                }
                pd = dummy;
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
