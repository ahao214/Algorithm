using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1123
{
    public class Class1123
    {

        public TreeNode LcaDeepestLeaves(TreeNode root)
        {
            return f(root).Item1;
        }

        private Tuple<TreeNode, int> f(TreeNode root)
        {
            if (root == null)
            {
                return new Tuple<TreeNode, int>(root, 0);
            }

            Tuple<TreeNode, int> left = f(root.left);
            Tuple<TreeNode, int> right = f(root.right);

            if (left.Item2 > right.Item2)
            {
                return new Tuple<TreeNode, int>(left.Item1, left.Item2 + 1);
            }
            if (left.Item2 < right.Item2)
            {
                return new Tuple<TreeNode, int>(right.Item1, right.Item2 + 1);
            }
            return new Tuple<TreeNode, int>(root, left.Item2 + 1);
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
