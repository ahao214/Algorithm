using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1080
{
    public class Class1080
    {
        public TreeNode SufficientSubset(TreeNode root, int limit)
        {
            bool haveSufficient = CheckSufficientLeaf(root, 0, limit);
            return haveSufficient ? root : null;
        }

        public bool CheckSufficientLeaf(TreeNode node, int sum, int limit)
        {
            if (node == null)
            {
                return false;
            }
            if (node.left == null && node.right == null)
            {
                return node.val + sum >= limit;
            }
            bool haveSufficientLeft = CheckSufficientLeaf(node.left, sum + node.val, limit);
            bool haveSufficientRight = CheckSufficientLeaf(node.right, sum + node.val, limit);
            if (!haveSufficientLeft)
            {
                node.left = null;
            }
            if (!haveSufficientRight)
            {
                node.right = null;
            }
            return haveSufficientLeft || haveSufficientRight;
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
