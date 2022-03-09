using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo102
{
    /*
     102. 二叉树的层序遍历
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
     */
    public class Class102
    {
        public IList<IList<int>> LevelOrder(TreeNode root)
        {
            if (root == null)
                return new List<IList<int>>();
            IList<TreeNode> prev = new[] { root };
            var result = new List<IList<TreeNode>>();
            while (prev.Count > 0)
            {
                result.Add(prev);
                prev = new List<TreeNode>();
                foreach (var node in result.Last())
                {
                    if (node == null)
                        continue;
                    if (node.left != null)
                        prev.Add(node.left);
                    if (node.right != null)
                        prev.Add(node.right);
                }
            }
            return result.Select(t => t.Select(n => n.val).ToArray() as IList<int>).ToArray();
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
