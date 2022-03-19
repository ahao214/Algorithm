using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo606
{
    public class Class606
    {
        public string Tree2str(TreeNode root)
        {
            if (root == null)
                return "";
            if (root.left == null && root.right == null)
                return root.val.ToString();
            StringBuilder sb = new StringBuilder();
            if (root.right == null)
            {
                return sb.Append(root.val).Append("(").Append(Tree2str(root.left)).Append(")").ToString();
            }
            return sb.Append(root.val).Append("(").Append(Tree2str(root.left)).Append(")(").Append(Tree2str(root.right)).Append(")").ToString();
        }
    }

    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right  null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
