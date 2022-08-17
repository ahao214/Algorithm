using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1302
{
    public class Class1302
    {

        int maxLevel = -1;
        int sum = 0;

        public int DeepestLeavesSum(TreeNode root)
        {
            DFS(root, 0);
            return sum;
        }

        public void DFS(TreeNode node, int level)
        {
            if (node == null)
            {
                return;
            }
            if (level > maxLevel)
            {
                maxLevel = level;
                sum = node.val;
            }
            else if (level == maxLevel)
            {
                sum += node.val;
            }
            DFS(node.left, level + 1);
            DFS(node.right, level + 1);
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
