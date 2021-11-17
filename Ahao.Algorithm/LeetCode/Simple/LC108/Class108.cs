using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LeetCode.Simple.LC108
{
    /// <summary>
    /// 108. 将有序数组转换为二叉搜索树
    /// </summary>
    public class Class108
    {
        public TreeNode SortedArrayToBST(int[] nums)
        {
            return help(nums, 0, nums.Length - 1);
        }

        public TreeNode help(int[] arr, int left, int right)
        {
            if (left > right)
            {
                return null;
            }
            int mid = (left + right) / 2;
            TreeNode root = new TreeNode(arr[mid]);
            root.left = help(arr, left, mid - 1);
            root.right = help(arr, mid + 1, right);
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
