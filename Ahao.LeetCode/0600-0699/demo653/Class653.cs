using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo653
{
    public class Class653
    {
        ISet<int> set = new HashSet<int>();
        /// <summary>
        /// 深度优先+哈希表
        /// </summary>
        /// <returns></returns>
        public bool FindTarget(TreeNode root, int k)
        {
            if (root == null)
            {
                return false;
            }
            if (set.Contains(k - root.val))
            {
                return true;
            }
            set.Add(root.val);
            return FindTarget(root.left, k) || FindTarget(root.right, k);
        }

        /// <summary>
        /// 广度优先+哈希表
        /// </summary>
        /// <param name="root"></param>
        /// <param name="k"></param>
        /// <returns></returns>
        public bool FingTarget1(TreeNode root, int k)
        {
            ISet<int> set = new HashSet<int>();
            Queue<TreeNode> q = new Queue<TreeNode>();
            q.Enqueue(root);
            while (q.Count > 0)
            {
                TreeNode node = q.Dequeue();
                if (set.Contains(k - node.val))
                {
                    return true;
                }
                set.Add(node.val);
                if (node.left != null)
                {
                    q.Enqueue(node.left);
                }
                if (node.right != null)
                {
                    q.Enqueue(node.right);
                }
            }
            return false;
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
