using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1022
{
    public class Class1022
    {
        /// <summary>
        /// 方法一：递归
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public int SumRootToLeaf(TreeNode root)
        {
            return DFS(root, 0);
        }

        public int DFS(TreeNode root, int val)
        {
            if (root == null)
            {
                return 0;
            }
            val = (val << 1) | root.val;
            if (root.left == null && root.right == null)
            {
                return val;
            }
            return DFS(root.left, val) + DFS(root.right, val);
        }


        /// <summary>
        /// 方法二：迭代
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public int SumRootToLeaf2(TreeNode root)
        {
            Stack<TreeNode> stack = new Stack<TreeNode>();
            int val = 0, ret = 0;
            TreeNode prev = null;
            while (root != null || stack.Count > 0)
            {
                while (root != null)
                {
                    val = (val << 1) | root.val;
                    stack.Push(root);
                    root = root.left;
                }
                root = stack.Peek();
                if (root.right == null || root.right == prev)
                {
                    if (root.left == null && root.right == null)
                    {
                        ret += val;
                    }
                    val >>= 1;
                    stack.Pop();
                    prev = root;
                    root = null;
                }
                else
                {
                    root = root.right;
                }
            }
            return ret;
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
