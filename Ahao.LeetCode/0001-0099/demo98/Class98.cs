using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo98
{
    /*
     98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。     
     */
    public class Class98
    {
        public bool IsValidBST(TreeNode root)
        {
            return IsValid(root, null, null);
        }

        private bool IsValid(TreeNode root, int? minValue, int? maxValue)
        {
            if (root == null)
                return true;
            if (minValue.HasValue && root.val <= minValue)
                return false;
            if (maxValue.HasValue && root.val >= maxValue)
                return false;
            return IsValid(root.left, minValue, root.val) && IsValid(root.right, root.val, maxValue);
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
