using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.NC193
{
    /// <summary>
    /// NC193 二叉树的前序遍历
    /// </summary>
    public class Class193
    {
        public List<int> preorderTraversal(TreeNode root)
        {
            var lst = new List<int>();
            preOrder(root, lst);
            return lst;
        }

        private void preOrder(TreeNode root, List<int> lst)
        {
            if (root == null)
            {
                return;
            }
            lst.Add(root.val);
            preOrder(root.left, lst);
            preOrder(root.right, lst);
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
