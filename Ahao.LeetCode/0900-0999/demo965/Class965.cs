using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo965
{
    public class Class965
    {
        public bool IsUnivalTree(TreeNode root)
        {
            if (root == null)
            {
                return true;
            }
            if (root.left != null)
            {
                if (root.val != root.left.val || !IsUnivalTree(root.left))
                {
                    return false;
                }
            }
            if (root.right != null)
            {
                if (root.val != root.right.val || !IsUnivalTree(root.right))
                {
                    return false;
                }
            }
            return true;
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
