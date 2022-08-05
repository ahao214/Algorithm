using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo623
{
    public class Class623
    {
        /// <summary>
        /// 深度优先
        /// </summary>
        /// <param name="root"></param>
        /// <param name="val"></param>
        /// <param name="depth"></param>
        /// <returns></returns>
        public TreeNode AddOneRow(TreeNode root, int val, int depth)
        {
            if (root == null)
            {
                return null;
            }
            if (depth == 1)
            {
                return new TreeNode(val, root, null);
            }
            if (depth == 2)
            {
                root.left = new TreeNode(val, root.left, null);
                root.right = new TreeNode(val, null, root.right);
            }
            else
            {
                root.left = AddOneRow(root.left, val, depth - 1);
                root.right = AddOneRow(root.right, val, depth - 1);
            }
            return root;
        }


        /// <summary>
        /// 广度优先
        /// </summary>
        /// <param name="root"></param>
        /// <param name="val"></param>
        /// <param name="depth"></param>
        /// <returns></returns>
        public TreeNode AddOneRow2(TreeNode root, int val, int depth)
        {
            if (depth == 1)
            {
                return new TreeNode(val, root, null);
            }
            IList<TreeNode> curLevel = new List<TreeNode>();
            curLevel.Add(root);
            for (int i = 1; i < depth - 1; i++)
            {
                IList<TreeNode> tmpt = new List<TreeNode>();
                foreach (TreeNode node in curLevel)
                {
                    if (node.left != null)
                    {
                        tmpt.Add(node.left);
                    }
                    if (node.right != null)
                    {
                        tmpt.Add(node.right);
                    }
                }
                curLevel = tmpt;
            }
            foreach (TreeNode node in curLevel)
            {
                node.left = new TreeNode(val, node.left, null);
                node.right = new TreeNode(val, null, node.right);
            }
            return root;
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
