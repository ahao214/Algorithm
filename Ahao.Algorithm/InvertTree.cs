using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 226. 翻转二叉树
    /// </summary>
    public class InvertTree
    {
        public TreeNode Method(TreeNode root)
        {
            if (root == null) return root;

            var temp = root.left;
            root.left = root.right;
            root.right = temp;

            Method(root.left);
            Method(root.right);

            return root;
        }
    }




    //Definition for a binary tree node.
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x) { val = x; }
    }

}
