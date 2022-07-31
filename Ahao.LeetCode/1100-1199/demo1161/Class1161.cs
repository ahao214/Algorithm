using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1161
{
    public class Class1161
    {
        private IList<int> sum = new List<int>();
        /// <summary>
        /// 深度优先搜索
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public int MaxLevelSum(TreeNode root)
        {
            DFS(root, 0);
            int ans = 0;
            for (int i = 0; i < sum.Count; ++i)
            {
                if (sum[i] > sum[ans])
                {
                    ans = i;
                }
            }
            return ans + 1; // 层号从 1 开始
        }

        private void DFS(TreeNode node, int level)
        {
            if (level == sum.Count)
            {
                sum.Add(node.val);
            }
            else
            {
                sum[level] += node.val;
            }
            if (node.left != null)
            {
                DFS(node.left, level + 1);
            }
            if (node.right != null)
            {
                DFS(node.right, level + 1);
            }
        }

        /// <summary>
        /// 广度优先搜索
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public int MaxLevelSum2(TreeNode root)
        {
            int ans = 1, maxSum = root.val;
            IList<TreeNode> q = new List<TreeNode>();
            q.Add(root);
            for (int level = 1; q.Count > 0; ++level)
            {
                IList<TreeNode> nq = new List<TreeNode>();
                int sum = 0;
                foreach (TreeNode node in q)
                {
                    sum += node.val;
                    if (node.left != null)
                    {
                        nq.Add(node.left);
                    }
                    if (node.right != null)
                    {
                        nq.Add(node.right);
                    }
                }
                if (sum > maxSum)
                {
                    maxSum = sum;
                    ans = level;
                }
                q = nq;
            }
            return ans;
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
}
