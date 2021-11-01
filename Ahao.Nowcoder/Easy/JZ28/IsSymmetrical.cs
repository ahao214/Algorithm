using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.JZ28
{
    /// <summary>
    /// JZ28 对称的二叉树
    /// </summary>
    public class IsSymmetrical
    {
        public bool Method(TreeNode pRoot)
        {
            if (pRoot == null)
            {
                return true;
            }
            return IsEqual(pRoot.left, pRoot.right);
        }
        public bool IsEqual(TreeNode lRoot, TreeNode rRoot)
        {
            if (lRoot == null && rRoot == null)
            {
                return true;
            }
            if (lRoot == null || rRoot == null || lRoot.val != rRoot.val)
            {
                return false;
            }
            bool leftEqual = IsEqual(lRoot.left, rRoot.right);
            bool rightEqual = IsEqual(lRoot.right, rRoot.left);
            return leftEqual && rightEqual;
        }
    }

    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x)
        {
            val = x;
        }
    }
}
