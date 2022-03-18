using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo124
{
    /// <summary>
    /// 124. 二叉树中的最大路径和
    /// </summary>
    public class Class124
    {
        public int MaxPathSum(TreeNode root)
        {
            if (root == null)
                return 0;
            return MaxPath(root).maxValue;
        }

        private (int maxValue, int partValue) MaxPath(TreeNode root)
        {
            if (root.left == null && root.right == null)
            {
                return (root.val, root.val);
            }
            if (root.left == null || root.right == null)
            {
                var child = MaxPath(root.left ?? root.right);
                return (Max(child.maxValue, TrimToZero(child.partValue) + root.val), Max(root.val + child.partValue, root.val));
            }

            var left = MaxPath(root.left);
            var right = MaxPath(root.right);

            return (Max(left.maxValue, right.maxValue, TrimToZero(left.partValue) + root.val + TrimToZero(right.partValue)),
                      Max(root.val + left.partValue, root.val + right.partValue, root.val));
        }

        private int TrimToZero(int x)
        {
            return x < 0 ? 0 : x;
        }

        private int Max(int x, int y)
        {
            return Math.Max(x, y);
        }

        private int Max(int x, int y, int z)
        {
            return Math.Max(z, Math.Max(x, y));
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
