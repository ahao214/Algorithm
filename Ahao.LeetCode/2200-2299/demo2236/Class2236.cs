using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2200_2299.demo2236
{
    public class Class2236
    {
        public bool CheckTree(TreeNode root)
        {
            if (root.val == root.left.val + root.right.val)
            {
                return true;
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
