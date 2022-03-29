using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo654
{
    public class Class654
    {
        public TreeNode ConstructMaximumBinaryTree(int[] nums)
        {
            if (nums == null || nums.Length == 0)
            {
                return null;
            }
            return findRoot(nums, 0, nums.Length);
        }

        private TreeNode findRoot(int[] arr, int left, int right)
        {
            if (left == right)
                return null;
            //找出[left,right]范围内的最大值的索引
            int maxIdx = left;
            for (int i = left + 1; i < right; i++)
            {
                if (arr[i] > arr[maxIdx])
                {
                    maxIdx = i;
                }
            }
            TreeNode root = new TreeNode(arr[maxIdx]);
            root.left = findRoot(arr, left, maxIdx);
            root.right = findRoot(arr, maxIdx + 1, right);
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
