using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Medium.NC5
{
    /// <summary>
    /// NC5 二叉树根节点到叶子节点的所有路径和
    /// </summary>
    public class Class5
    {
        public int sumNumbers(TreeNode root)
        {
            return dfs(root, 0);
        }

        public int dfs(TreeNode root, int prevSum)
        {
            if (root == null)
            {
                return 0;
            }
            int sum = prevSum * 10 + root.val;
            if (root.left == null && root.right == null)
            {
                return sum;
            }
            return dfs(root.left, sum) + dfs(root.right, sum);
        }
    }

    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x)
        {
            val = x;
        }
    }
}
