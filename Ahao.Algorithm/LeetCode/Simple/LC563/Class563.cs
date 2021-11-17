using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LeetCode.Simple.LC563
{
    /// <summary>
    /// 563. 二叉树的坡度
    /// </summary>
    public class Class563
    {
        int res = 0;
        public int FindTilt(TreeNode root)
        {
            DFS(root);
            return res;
        }

        private int DFS(TreeNode node)
        {
            if (node == null)
            {
                return 0;
            }
            int sumLeft = DFS(node.left);
            int sumRight = DFS(node.right);
            res += Math.Abs(sumLeft - sumRight);
            return sumLeft + sumRight + node.val;
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
