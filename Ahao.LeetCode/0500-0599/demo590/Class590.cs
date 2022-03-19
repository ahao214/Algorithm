using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo590
{
    /*
     590. N 叉树的后序遍历
给定一个 n 叉树的根节点 root ，返回 其节点值的 后序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
     */
    public class Class590
    {
        /// <summary>
        /// 递归
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public IList<int> Postorder(Node root)
        {
            IList<int> res = new List<int>();
            if (root == null)
                return res;
            Helper(root, res);
            return res;
        }

        private void Helper(Node root, IList<int> res)
        {
            if (root == null)
                return;
            foreach (Node ch in root.children)
            {
                Helper(ch, res);
            }
            res.Add(root.val);
        }

        /// <summary>
        /// 迭代
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public IList<int> Postorder1(Node root)
        {
            IList<int> res = new List<int>();
            if (root == null)
            {
                return res;
            }
            Dictionary<Node, int> dictionary = new Dictionary<Node, int>();
            Stack<Node> stack = new Stack<Node>();
            Node node = root;
            while (stack.Count > 0 || node != null)
            {
                while (node != null)
                {
                    stack.Push(node);
                    IList<Node> childrenList = node.children;
                    if (childrenList != null && childrenList.Count > 0)
                    {
                        dictionary.Add(node, 0);
                        node = childrenList[0];
                    }
                    else
                    {
                        node = null;
                    }
                }
                node = stack.Peek();
                int index = (dictionary.ContainsKey(node) ? dictionary[node] : -1) + 1;
                IList<Node> children = node.children;
                if (children != null && children.Count > index)
                {
                    dictionary[node] = index;
                    node = children[index];
                }
                else
                {
                    res.Add(node.val);
                    stack.Pop();
                    dictionary.Remove(node);
                    node = null;
                }
            }
            return res;
        }

        /// <summary>
        /// 迭代优化
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public IList<int> Postorder2(Node root)
        {
            IList<int> res = new List<int>();
            if (root == null)
            {
                return res;
            }

            Stack<Node> stack = new Stack<Node>();
            ISet<Node> visited = new HashSet<Node>();
            stack.Push(root);
            while (stack.Count > 0)
            {
                Node node = stack.Peek();
                /* 如果当前节点为叶子节点或者当前节点的子节点已经遍历过 */
                if (node.children.Count == 0 || visited.Contains(node))
                {
                    stack.Pop();
                    res.Add(node.val);
                    continue;
                }
                for (int i = node.children.Count - 1; i >= 0; i--)
                {
                    stack.Push(node.children[i]);
                }
                visited.Add(node);
            }
            return res;
        }
    }

    // Definition for a Node.
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
