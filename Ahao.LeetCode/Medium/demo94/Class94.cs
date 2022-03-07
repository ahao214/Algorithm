using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo94
{
    /*
     94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
     */
    public class Class94
    {
        public IList<int> InorderTraversal(TreeNode root)
        {
            var result = new List<int>();
            Inorder(root, result);
            return result;
        }

        private void Inorder(TreeNode root, List<int> result)
        {
            if (root == null)
                return;
            Inorder(root.left, result);
            result.Add(root.val);
            Inorder(root.right, result);
        }

        public IList<int> InorderTraversal1(TreeNode root)
        {
            if (root == null)
                return Array.Empty<int>();
            var result = new List<int>();
            var stack = new Stack<(TreeNode node, bool twise)>();
            stack.Push((root, false));
            Inorder1(stack, result);
            return result;
        }

        private void Inorder1(Stack<(TreeNode node, bool twise)> stack, List<int> result)
        {
            while (stack.Count > 0)
            {
                var item = stack.Pop();
                var node = item.node;
                if (item.twise)
                {
                    result.Add(node.val);
                    if (node.right != null)
                        stack.Push((node.right, false));
                }
                else
                {
                    stack.Push((node, true));
                    if (node.left != null)
                        stack.Push((node.left, false));
                }
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
