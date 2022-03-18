using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo113
{
    /*
     113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。
     */
    public class Class113
    {
        public IList<IList<int>> PathSum(TreeNode root, int targetSum)
        {
            var results = new List<IList<int>>();
            var path = new List<int>();
            PathSum(root, targetSum, path, results);
            return results;
        }

        private void PathSum(TreeNode root, int sum, List<int> path, List<IList<int>> results)
        {
            switch (root)
            {
                case null:
                    return;
                case var _ when root.left == null && root.right == null:
                    if (sum == root.val)
                    {
                        path.Add(root.val);
                        results.Add(path.ToArray());
                        path.RemoveAt(path.Count - 1);
                    }
                    return;
                default:
                    path.Add(root.val);
                    PathSum(root.left, sum - root.val, path, results);
                    PathSum(root.right, sum - root.val, path, results);
                    path.RemoveAt(path.Count - 1);
                    return;
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
