using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo404
{
    /// <summary>
    /// 404. 左叶子之和
    /// </summary>
    public class Class404
    {
        public int SumOfLeftLeaves(TreeNode root)
        {
            int leftSum = 0;
            SumOfLeft(root, ref leftSum);
            return leftSum;
        }
        public void SumOfLeft(TreeNode node, ref int sum)
        {
            if (node == null)
            {
                return;
            }

            if (node.left != null && node.left.left == null && node.left.right == null)
            {
                sum += node.left.val;
            }

            SumOfLeft(node.left, ref sum);
            SumOfLeft(node.right, ref sum);
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
