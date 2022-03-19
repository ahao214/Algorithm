using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo572
{
    /// <summary>
    /// 572. 另一棵树的子树
    /// </summary>
    public class Class572
    {
        public bool IsSubtree(TreeNode root, TreeNode subRoot)
        {
            if (root == null)
            {
                return false;
            }

            return CheckTree(root, subRoot) || IsSubtree(root.left, subRoot) || IsSubtree(root.right, subRoot);
        }

        private bool CheckTree(TreeNode a, TreeNode b)
        {
            if (a == null && b == null)
            {
                return true;
            }

            if (a == null || b == null)
            {
                return false;
            }

            if (a.val == b.val)
            {
                return CheckTree(a.left, b.left) && CheckTree(a.right, b.right);
            }
            return false;
        }
    }


    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
