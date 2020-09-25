using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 100.相同的树
    /// </summary>
    public class IsSameTree
    {
        public bool Method(TreeNode p, TreeNode q)
        {            
            if (p == null && q == null)
            {
                return true;
            }
            else if(p==null || q==null || p.val !=q.val)
            {
                return false;
            }
            else
            {
                bool IsLeftSame = Method(p.left, q.left);
                bool IsRightSame = Method(p.right, q.right);
                return IsLeftSame && IsRightSame;
            }            
        }
    }

    //Definition for a binary tree node.
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
