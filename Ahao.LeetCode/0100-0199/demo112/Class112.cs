using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo112
{
    /*
     112. 路径总和
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

叶子节点 是指没有子节点的节点。
     */
    public class Class112
    {
        public bool HasPathSum(TreeNode root, int targetSum)
        {
            switch (root)
            {
                case null:
                    return false;
                case var _ when root.left == null && root.right == null:
                    return root.val == targetSum;
                default:
                    return HasPathSum(root.right, targetSum - root.val) || HasPathSum(root.left, targetSum - root.val);
            }
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
