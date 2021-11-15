using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 101.对称二叉树
    /// </summary>
    public class IsSymmetric
    {
        public bool Method(TreeNode root)
        {            
            return IsEqual(root, root);
        }

        public bool IsEqual(TreeNode rootLeft ,TreeNode rootRight)
        {
            if(rootLeft == null && rootRight == null )
            {
                return true;
            }
            if(rootLeft == null || rootRight == null || rootLeft.val != rootRight.val )
            {
                return false;
            }
            bool IsLeftEqual = IsEqual(rootLeft .left ,rootRight .right );
            bool IsRightEqual = IsEqual(rootLeft.right, rootRight.left);
            return IsLeftEqual && IsRightEqual;
        }
    }


    //Definition for a binary tree node.
    //public class TreeNode
    //{
    //    public int val;
    //    public TreeNode left;
    //    public TreeNode right;
    //    public TreeNode(int x) { val = x; }
    //}
}
