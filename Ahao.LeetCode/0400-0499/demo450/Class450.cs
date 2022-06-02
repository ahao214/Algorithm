using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo450
{
    public class Class450
    {
        /// <summary>
        /// 方法一：递归
        /// </summary>
        /// <param name="root"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        public TreeNode DeleteNode(TreeNode root, int key)
        {
            if (root == null)
            {
                return null;
            }
            if (root.val > key)
            {
                root.left = DeleteNode(root.left, key);
                return root;
            }
            if (root.val < key)
            {
                root.right = DeleteNode(root.right, key);
                return root;
            }
            if (root.val == key)
            {
                if (root.left == null && root.right == null)
                {
                    return null;
                }
                if (root.right == null)
                {
                    return root.left;
                }
                if (root.left == null)
                {
                    return root.right;
                }
                TreeNode successor = root.right;
                while (successor.left != null)
                {
                    successor = successor.left;
                }
                root.right = DeleteNode(root.right, successor.val);
                successor.right = root.right;
                successor.left = root.left;
                return successor;
            }
            return root;
        }


        /// <summary>
        /// 方法二：迭代
        /// </summary>
        /// <param name="root"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        public TreeNode DeleteNode2(TreeNode root, int key)
        {
            TreeNode cur = root, curParent = null;
            while (cur != null && cur.val != key)
            {
                curParent = cur;
                if (cur.val > key)
                {
                    cur = cur.left;
                }
                else
                {
                    cur = cur.right;
                }
            }
            if (cur == null)
            {
                return root;
            }
            if (cur.left == null && cur.right == null)
            {
                cur = null;
            }
            else if (cur.right == null)
            {
                cur = cur.left;
            }
            else if (cur.left == null)
            {
                cur = cur.right;
            }
            else
            {
                TreeNode successor = cur.right, successorParent = cur;
                while (successor.left != null)
                {
                    successorParent = successor;
                    successor = successor.left;
                }
                if (successorParent.val == cur.val)
                {
                    successorParent.right = successor.right;
                }
                else
                {
                    successorParent.left = successor.right;
                }
                successor.right = cur.right;
                successor.left = cur.left;
                cur = successor;
            }
            if (curParent == null)
            {
                return cur;
            }
            else
            {
                if (curParent.left != null && curParent.left.val == key)
                {
                    curParent.left = cur;
                }
                else
                {
                    curParent.right = cur;
                }
                return root;
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
