using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo101
{
    /*
     101. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。
     */
    public class Class101
    {
        public bool IsSymmetric(TreeNode root)
        {
            if (root == null)
                return true;
            return IsSame(root.left, root.right);
        }

        private bool IsSame(TreeNode t1, TreeNode t2)
        {
            if (t1 == null)
                return t2 == null;
            return t2 != null && t1.val == t2.val && IsSame(t1.left, t2.right) && IsSame(t1.right, t2.left);
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
