using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1373
{
    public class Class1373
    {

        const int INF = 0x3f3f3f3f;
        int res;

        public class SubTree
        {
            public bool isBST;
            public int minValue;
            public int maxValue;
            public int sumValue;

            public SubTree(bool isBST, int minValue, int maxValue, int sumValue)
            {
                this.isBST = isBST;
                this.minValue = minValue;
                this.maxValue = maxValue;
                this.sumValue = sumValue;
            }
        }

        public int MaxSumBST(TreeNode root)
        {
            res = 0;
            DFS(root);
            return res;
        }

        public SubTree DFS(TreeNode root)
        {
            if (root == null)
            {
                return new SubTree(true, INF, -INF, 0);
            }
            SubTree left = DFS(root.left);
            SubTree right = DFS(root.right);

            if (left.isBST && right.isBST && root.val > left.maxValue && root.val < right.minValue)
            {
                int sum = root.val + left.sumValue + right.sumValue;
                res = Math.Max(res, sum);
                return new SubTree(true, Math.Min(left.minValue, root.val), Math.Max(root.val, right.maxValue), sum);
            }
            else
            {
                return new SubTree(false, 0, 0, 0);
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
