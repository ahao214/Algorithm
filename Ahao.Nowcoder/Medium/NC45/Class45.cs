using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Medium.NC45
{
    /// <summary>
    /// NC45 实现二叉树先序，中序和后序遍历
    /// </summary>
    public class Class45
    {
        public List<List<int>> threeOrders(TreeNode root)
        {
            List<int> pre = new List<int>();
            List<int> mid = new List<int>();
            List<int> post = new List<int>();
            PreOrder(root, pre);
            InOrder(root, mid);
            PostOrder(root, post);

            List<List<int>> res = new List<List<int>>();
            res.Add(pre);
            res.Add(mid);
            res.Add(post);
            return res;
        }

        //先序
        private void PreOrder(TreeNode root, List<int> res)
        {
            if (root == null)
            {
                return;
            }
            res.Add(root.val);
            PreOrder(root.left, res);
            PreOrder(root.right, res);
        }


        //中序
        private void InOrder(TreeNode root, List<int> res)
        {
            if (root == null)
            {
                return;
            }
            InOrder(root.left, res);
            res.Add(root.val);
            InOrder(root.right, res);
        }


        //后序
        private void PostOrder(TreeNode root, List<int> res)
        {
            if (root == null)
            {
                return;
            }
            PostOrder(root.left, res);
            PostOrder(root.right, res);
            res.Add(root.val);
        }
    }


    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;

        public TreeNode(int x)
        {
            val = x;
        }
    }
}
