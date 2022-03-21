using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo589
{
    public class Class589
    {
        /// <summary>
        /// 递归
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public IList<int> Preorder(Node root)
        {
            IList<int> res = new List<int>();
            if (root == null)
                return res;
            Helper(root, res);
            return res;
        }

        private void Helper(Node node, IList<int> res)
        {
            if (node == null)
                return;
            res.Add(node.val);
            foreach (Node ch in node.children)
            {
                Helper(ch, res);
            }
        }

        /// <summary>
        /// 迭代优化
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public IList<int> Preorder1(Node root)
        {
            IList<int> res = new List<int>();
            if (root == null)
                return res;

            Stack<Node> stk = new Stack<Node>();
            stk.Push(root);
            while (stk.Count > 0)
            {
                Node node = stk.Pop();
                res.Add(node.val);
                for (int i = node.children.Count - 1; i >= 0; i--)
                {
                    stk.Push(node.children[i]);
                }
            }
            return res;
        }
    }

    public class Node
    {
        public int val;
        public IList<Node> children;

        public Node()
        {
        }

        public Node(int _val)
        {
            val = _val;
        }

        public Node(int _val, IList<Node> _children)
        {
            val = _val;
            children = _children;
        }
    }
}
