using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo129
{
    /// <summary>
    /// 129. 求根节点到叶节点数字之和
    /// </summary>
    public class Class129
    {
        public int SumNumbers(TreeNode root)
        {
            return SumNums(root, 0);
        }

        private int SumNums(TreeNode root, int n)
        {
            if (root == null)
            {
                return 0;
            }
            var sum = n * 10 + root.val;
            return (root.left == null && root.right == null) ?
               sum
                : SumNums(root.left, sum) + SumNums(root.right, sum);
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
