using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1026
{
    public class Class1026
    {
        public int MaxAncestorDiff(TreeNode root)
        {
            if (root == null)
                return 0;
            return dfs(root, root.val, root.val);
        }

        private int dfs(TreeNode root, int min, int max)
        {
            if (root == null)
                return 0;
            min = Math.Min(root.val, min);
            max = Math.Max(root.val, max);
            if (root.left == null && root.right == null)
                return max - min;

            int rightVale = dfs(root.right, min, max);
            int leftValue = dfs(root.left, min, max);
            return Math.Max(rightVale, leftValue);
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
