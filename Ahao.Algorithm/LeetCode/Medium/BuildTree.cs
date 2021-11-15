using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 106. 从中序与后序遍历序列构造二叉树
    /// </summary>
    public class BuildTree
    {
        public TreeNode Method(int[] inorder, int[] postorder)
        {
            if (inorder == null || postorder == null || inorder.Length <= 0 || postorder.Length <= 0)
            {
                return null;
            }

            var dictionary = new Dictionary<int, int>();
            for (int i = 0; i < inorder.Length; ++i)
            {
                dictionary.Add(inorder[i], i);
            }
            return Build(inorder, postorder, dictionary, 0, postorder.Length - 1, postorder.Length - 1);
        }

        private TreeNode Build(int[] inorder, int[] postorder, Dictionary<int, int> dictionary, int start, int end, int root)
        {
            var rootNode = new TreeNode(postorder[root]);

            if (start == end)
            {
                return rootNode;
            }

            int pos = dictionary[postorder[root]];

            if (pos > start)
            {
                rootNode.left = Build(inorder, postorder, dictionary, start, pos - 1, pos + root - end - 1);
            }
            if (pos < end)
            {
                rootNode.right = Build(inorder, postorder, dictionary, pos + 1, end, root - 1);
            }

            return rootNode;
        }
    }

    //public class TreeNode
    //{
    //    public int val;
    //    public TreeNode left;
    //    public TreeNode right;
    //    public TreeNode(int x) { val = x; }
    //}
}
