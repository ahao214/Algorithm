using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.NC192
{
    /// <summary>
    /// NC192 二叉树的后序遍历
    /// </summary>
    public class Class192
    {
        public List<int> postorderTraversal(TreeNode root)
        {
            var lst = new List<int>();
            postOrder(root, lst);
            return lst;
        }

        public void postOrder(TreeNode root, List<int> lst)
        {
            if (root == null)
            {
                return;
            }
            postOrder(root.left, lst);
            postOrder(root.right, lst);
            lst.Add(root.val);
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
