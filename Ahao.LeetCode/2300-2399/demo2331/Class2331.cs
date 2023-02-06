using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2331
{
    public class Class2331
    {
        public bool EvaluateTree(TreeNode root)
        {
            if (root.left == null)
            {
                return root.val == 1;
            }
            if (root.val == 2)
            {
                return EvaluateTree(root.left) || EvaluateTree(root.right);
            }
            else
            {
                return EvaluateTree(root.left) && EvaluateTree(root.right);
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
