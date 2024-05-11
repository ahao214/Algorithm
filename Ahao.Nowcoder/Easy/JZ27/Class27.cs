using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.JZ27
{
    /// <summary>
    /// JZ27 二叉树的镜像
    /// </summary>
    public class Class27
    {
        public TreeNode Mirror(TreeNode pRoot)
        {
            if (pRoot == null)
            {
                return null;
            }
            TreeNode leftMirror = Mirror(pRoot.left);
            TreeNode rightMirror = Mirror(pRoot.right);
            pRoot.left = rightMirror;
            pRoot.right = leftMirror;
            return pRoot;
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
