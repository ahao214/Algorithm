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



        public TreeNode BstToGst2(TreeNode root)
        {
            int sum = 0;
            TreeNode node = root;

            while (node != null)
            {
                if (node.right == null)
                {
                    sum += node.val;
                    node.val = sum;
                    node = node.left;
                }
                else
                {
                    TreeNode succ = GetSuccessor(node);
                    if (succ.left == null)
                    {
                        succ.left = node;
                        node = node.right;
                    }
                    else
                    {
                        succ.left = null;
                        sum += node.val;
                        node.val = sum;
                        node = node.left;
                    }
                }
            }

            return root;
        }

        public TreeNode GetSuccessor(TreeNode node)
        {
            TreeNode succ = node.right;
            while (succ.left != null && succ.left != node)
            {
                succ = succ.left;
            }
            return succ;
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
