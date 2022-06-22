using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo513
{
    public class Class513
    {

        #region 深度优先搜索

        int curVal = 0;
        int curHeight = 0;

        public int FindBottomLeftValue(TreeNode root)
        {
            int curHeight = 0;
            DFS(root, 0);
            return curVal;
        }

        public void DFS(TreeNode root, int height)
        {
            if (root == null)
            {
                return;
            }
            height++;
            DFS(root.left, height);
            DFS(root.right, height);
            if (height > curHeight)
            {
                curHeight = height;
                curVal = root.val;
            }
        }

        #endregion


        #region 广度优先搜索


        public int FindBottomLeftValue2(TreeNode root)
        {
            int ret = 0;
            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            while (queue.Count > 0)
            {
                TreeNode p = queue.Dequeue();
                if (p.right != null)
                {
                    queue.Enqueue(p.right);
                }
                if (p.left != null)
                {
                    queue.Enqueue(p.left);
                }
                ret = p.val;
            }
            return ret;
        }


        #endregion
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
