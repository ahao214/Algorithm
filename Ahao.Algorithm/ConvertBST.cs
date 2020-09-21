using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 538.把二叉搜索树转换为累加树
    /// </summary>
    public class ConvertBST
    {
        int sum = 0;
        public TreeNode Method(TreeNode root)
        {
            DFS(root);
            return root;
        }

        private void DFS(TreeNode node)
        {
            if (node == null)
            {
                return;
            }
            DFS(node.right);
            node.val += sum;
            sum = node.val;
            DFS(node.left);
        }

        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int x) { val = x; }
        }
    }
}
