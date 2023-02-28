using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo337
{
    public class Class337
    {
        public int Rob(TreeNode root)
        {
            if (root == null)
                return 0;
            int money = root.val;
            if (root.left != null)
            {
                money += Rob(root.left.left) + Rob(root.left.right);
            }
            if (root.right != null)
            {
                money += Rob(root.right.left) + Rob(root.right.right);
            }
            return Math.Max(money, Rob(root.left) + Rob(root.right));
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
