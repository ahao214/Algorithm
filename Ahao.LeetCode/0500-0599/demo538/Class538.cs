using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo538
{
    /// <summary>
    /// 538. 把二叉搜索树转换为累加树
    /// </summary>
    public class Class538
    {
        int sum = 0;
        public TreeNode ConvertBST(TreeNode root)
        {
            dfs(root);
            return root;
        }
        private void dfs(TreeNode node)
        {
            if (node == null)
            {
                return;
            }
            dfs(node.right);
            node.val += sum;
            sum = node.val;
            dfs(node.left);
        }
    }

    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x) { val = x; }
    }
}
