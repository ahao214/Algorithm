using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo103
{
    /*
     103. 二叉树的锯齿形层序遍历
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
     */
    public class Class103
    {
        public IList<IList<int>> ZigzagLevelOrder(TreeNode root)
        {
            if (root == null)
                return new List<IList<int>>();

            var nodes = new List<TreeNode>() { root };
            var results = new List<IList<int>>();
            var leftToRight = true;
            while (nodes.Count > 0)
            {
                var count = nodes.Count;
                var result = new int[count];
                if (leftToRight)
                {
                    for (int i = 0; i < count; i++)
                        result[i] = nodes[i].val;
                }
                else
                {
                    for (int i = 0, j = count - 1; i < count; i++, j--)
                    {
                        result[j] = nodes[i].val;
                    }
                }
                results.Add(result);
                for (int i = 0; i < count; i++)
                {
                    var node = nodes[i];
                    if (node.left != null)
                        nodes.Add(node.left);
                    if (node.right != null)
                        nodes.Add(node.right);
                }
                nodes.RemoveRange(0, count);
                leftToRight = !leftToRight;
            }
            return results;
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

