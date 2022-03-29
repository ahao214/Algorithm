using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo99
{
    public class Class99
    {
        public void RecoverTree(TreeNode root)
        {
            TreeNode prev = null;
            TreeNode n1 = null;
            TreeNode n2 = null;
            foreach (var node in MorrisTraver(root))
            {
                if (prev != null && prev.val > node.val)
                {
                    if (n1 == null) n1 = prev;
                    n2 = node;
                }
                prev = node;
            }
            if (n1 != null)
            {
                var tmp = n1.val;
                n1.val = n2.val;
                n2.val = tmp;
            }
        }

        private IEnumerable<TreeNode> MorrisTraver(TreeNode node)
        {

            while (node != null)
            {
                if (node.left == null)
                {
                    yield return node;
                    node = node.right;
                }
                else
                {
                    var prev = node.left;
                    while (prev.right != null && prev.right != node)
                        prev = prev.right;
                    if (prev.right == null)
                    {
                        prev.right = node;
                        node = node.left;
                    }
                    else
                    {
                        prev.right = null;
                        yield return node;
                        node = node.right;
                    }
                }
            }
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
