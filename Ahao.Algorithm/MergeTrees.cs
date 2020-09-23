using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 617.合并二叉树
    /// </summary>
    public class MergeTrees
    {
        public TreeNode Method(TreeNode t1, TreeNode t2)
        {
            if (t1 == null && t2 == null)
            {
                return null;
            }
            if (t1 == null)
            {
                return t2;
            }
            if (t2 == null)
            {
                return t1;
            }
            t1.val = t1.val + t2.val;
            t1.left = Method(t1.left, t2.left);
            t1.right = Method(t1.right, t2.right);
            return t1;
        }

        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int x) { val = x; }
        }
    }
}
