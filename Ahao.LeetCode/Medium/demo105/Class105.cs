using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo105
{
    /*
     105. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
     */
    public class Class105
    {
        public TreeNode BuildTree(int[] preorder, int[] inorder)
        {
            if (preorder == null || preorder.Length == 0)
            {
                return null;
            }
            if (inorder == null || inorder.Length != preorder.Length)
            {
                throw new ArgumentException();
            }

            var index = new InvertedIndex(inorder);
            return BuildTree(preorder, 0, inorder, 0, inorder.Length, index);
        }

        private TreeNode BuildTree(int[] preorder, int pi, int[] inorder, int ii, int count, InvertedIndex index)
        {
            if (count == 0)
            {
                return null;
            }

            var pn = index.IndexOf(preorder[pi]);
            if (pn < 0)
            {
                throw new ArgumentException();
            }
            if (pn < ii || pn >= ii + count)
            {
                throw new ArgumentException();
            }
            var leftTreeSize = pn - ii;
            var rightTreeSize = count - leftTreeSize - 1;

            return new TreeNode(preorder[pi]) {
                left = BuildTree(preorder, pi + 1, inorder, ii, leftTreeSize, index),
                right = BuildTree(preorder, pi + 1 + leftTreeSize, inorder, pn + 1, rightTreeSize, index)
            };
        }

        class InvertedIndex
        {
            private readonly int[] _array;
            private readonly int[] _indies;
            public InvertedIndex(int[] array)
            {
                _array = (int[])array.Clone();
                _indies = new int[_array.Length];
                for (int i = 0; i < _indies.Length; i++)
                {
                    _indies[i] = i;
                }
                Array.Sort(_array, _indies);
            }

            public int IndexOf(int n)
            {
                var i = Array.BinarySearch(_array, n);
                if (i >= 0)
                {
                    return _indies[i];
                }
                return -1;
            }

            public bool Contains(int n) => IndexOf(n) >= 0;
        }



        public TreeNode BuildTree2(int[] preorder, int[] inorder)
        {
            return myBuild(preorder, 0, preorder.Length - 1, inorder, 0, inorder.Length - 1);
        }
        private TreeNode myBuild(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd)
        {
            if (inStart > inEnd)
                return null;
            int rootVal = preorder[preStart];
            int index = -1;
            for (int i = inStart; i <= inEnd; i++)
            {
                if (inorder[i] == rootVal)
                {
                    index = i;
                    break;
                }
            }
            int inLeft = index - inStart - 1;
            TreeNode root = new TreeNode(rootVal);
            root.left = myBuild(preorder, preStart + 1, preStart + 1 + inLeft, inorder, inStart, index - 1);
            root.right = myBuild(preorder, preStart + 2 + inLeft, preEnd, inorder, index + 1, inEnd);
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
