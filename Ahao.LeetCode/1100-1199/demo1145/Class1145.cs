using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1145
{
    public class Class1145
    {

        TreeNode xNode;

        public bool BtreeGameWinningMove(TreeNode root, int n, int x)
        {
            Find(root, x);
            int leftSize = GetSubtreeSize(xNode.left);
            if (leftSize >= (n + 1) / 2)
            {
                return true;
            }
            int rightSize = GetSubtreeSize(xNode.right);
            if (rightSize >= (n + 1) / 2)
            {
                return true;
            }
            int remain = n - 1 - leftSize - rightSize;
            return remain >= (n + 1) / 2;
        }

        public void Find(TreeNode node, int x)
        {
            if (xNode != null || node == null)
            {
                return;
            }
            if (node.val == x)
            {
                xNode = node;
                return;
            }
            Find(node.left, x);
            Find(node.right, x);
        }

        public int GetSubtreeSize(TreeNode node)
        {
            if (node == null)
            {
                return 0;
            }
            return 1 + GetSubtreeSize(node.left) + GetSubtreeSize(node.right);
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
