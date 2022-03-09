using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo589
{
    /*
     589. N 叉树的前序遍历
    给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

    n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
     */
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
