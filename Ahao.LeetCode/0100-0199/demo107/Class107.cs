using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo107
{
    /// <summary>
    /// 107. 二叉树的层序遍历 II
    /// </summary>
    public class Class107
    {
        public IList<IList<int>> LevelOrderBottom(TreeNode root)
        {
            return EnumNodes(root, 0).GroupBy(t => t.level)
                .Select(g => g.Select(t => t.node.val).ToList() as IList<int>).Reverse().ToList();
        }

        private IEnumerable<(TreeNode node, int level)> EnumNodes(TreeNode root, int level)
        {
            if (root == null)
            {
                yield break;
            }
            yield return (root, level);
            foreach (var node in EnumNodes(root.left, level + 1))
            {
                yield return node;
            }

            foreach (var node in EnumNodes(root.right, level + 1))
            {
                yield return node;
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
