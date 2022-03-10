using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo110
{
    /*
     110. 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
     */
    public class Class110
    {
        public bool IsBalanced(TreeNode root)
        {
            return root == null ||
               IsBalanced(root.left) && IsBalanced(root.right) && Math.Abs(Depth(root.left) - Depth(root.right)) <= 1;
        }

        private int Depth(TreeNode root)
        {
            return root == null ? 0 :
                Math.Max(Depth(root.left), Depth(root.right)) + 1;
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
