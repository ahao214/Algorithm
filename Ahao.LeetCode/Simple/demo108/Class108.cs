using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo108
{
    /*
     108. 将有序数组转换为二叉搜索树
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
     */
    public class Class108
    {
        public TreeNode SortedArrayToBST(int[] nums)
        {
            return SortedArray(nums.AsSpan());
        }

        private TreeNode SortedArray(Span<int> span)
        {
            return span.Length == 0 ? null : new TreeNode(span[span.Length / 2]) {
                left = SortedArray(span.Slice(0, span.Length / 2)),
                right = SortedArray(span.Slice(span.Length / 2 + 1))
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
