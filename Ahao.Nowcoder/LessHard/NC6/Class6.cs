using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.LessHard.NC6
{
    /// <summary>
    /// NC6 二叉树中的最大路径和
    /// </summary>
    public class Class6
    {
        int maxSum = int.MinValue;
        public int maxPathSum(TreeNode root)
        {
            MaxGain(root);
            return maxSum;
        }

        int MaxGain(TreeNode node)
        {
            if (node == null)
            {
                return 0;
            }

            // 递归计算左右子节点的最大贡献值
            // 只有在最大贡献值大于 0 时，才会选取对应子节点
            int leftGain = Math.Max(MaxGain(node.left), 0);
            int rightGain = Math.Max(MaxGain(node.right), 0);

            // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
            int priceNewpath = node.val + leftGain + rightGain;

            // 更新答案
            maxSum = Math.Max(maxSum, priceNewpath);

            // 返回节点的最大贡献值
            return node.val + Math.Max(leftGain, rightGain);

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
