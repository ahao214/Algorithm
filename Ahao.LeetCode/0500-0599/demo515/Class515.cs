using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo515
{
    public class Class515
    {
        /// <summary>
        /// 深度优先
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public IList<int> LargestValues(TreeNode root)
        {
            if (root == null)
            {
                return new List<int>();
            }
            IList<int> res = new List<int>();
            DFS(res, root, 0);
            return res;
        }

        public void DFS(IList<int> res, TreeNode root, int curHeight)
        {
            if (curHeight == res.Count)
            {
                res.Add(root.val);
            }
            else
            {
                res[curHeight] = Math.Max(res[curHeight], root.val);
            }
            if (root.left != null)
            {
                DFS(res, root.left, curHeight + 1);
            }
            if (root.right != null)
            {
                DFS(res, root.right, curHeight + 1);
            }
        }

        /// <summary>
        /// 广度优先
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public IList<int> LargestValues2(TreeNode root)
        {
            if (root == null)
            {
                return new List<int>();
            }
            IList<int> res = new List<int>();
            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            while (queue.Count > 0)
            {
                int len = queue.Count;
                int maxVal = int.MinValue;
                while (len > 0)
                {
                    len--;
                    TreeNode t = queue.Dequeue();
                    maxVal = Math.Max(maxVal, t.val);
                    if (t.left != null)
                    {
                        queue.Enqueue(t.left);
                    }
                    if (t.right != null)
                    {
                        queue.Enqueue(t.right);
                    }
                }
                res.Add(maxVal);
            }
            return res;
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
