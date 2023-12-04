using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1038
{
    public class Class1038
    {
        int sum = 0;
        public TreeNode BstToGst(TreeNode root)
        {            
            if (root != null)
            {
                BstToGst(root.right);
                sum += root.val;
                root.val = sum;
                BstToGst(root.left);
            }
            return root;
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
