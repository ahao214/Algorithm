using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.JZ55
{
    /// <summary>
    /// JZ55 二叉树的深度
    /// </summary>
    public class Class55
    {
        public int TreeDepth(TreeNode pRoot)
        {
            if (pRoot == null)
            {
                return 0;
            }
            return Math.Max(TreeDepth(pRoot.left), TreeDepth(pRoot.right)) + 1;
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
