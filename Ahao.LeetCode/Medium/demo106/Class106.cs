using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo106
{
    /*
     106. 从中序与后序遍历序列构造二叉树
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
     */
    public class Class106
    {
        public TreeNode BuildTree(int[] inorder, int[] postorder)
        {
            return BuildTree(inorder.AsSpan(), postorder.AsSpan());
        }

        private TreeNode BuildTree(Span<int> inorder, Span<int> postorder)
        {
            if (postorder.Length == 0)
                return null;
            var pn = inorder.IndexOf(postorder[postorder.Length - 1]);
            var leftSize = pn;
            var rightSize = postorder.Length - 1 - leftSize;
            return new TreeNode(postorder[postorder.Length - 1]) {
                left = BuildTree(inorder.Slice(0, leftSize), postorder.Slice(0, leftSize)),
                right = BuildTree(inorder.Slice(pn + 1), postorder.Slice(leftSize, rightSize))
            };
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
