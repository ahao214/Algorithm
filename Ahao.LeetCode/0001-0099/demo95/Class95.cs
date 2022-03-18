using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo95
{
    /*
     95. 不同的二叉搜索树 II
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
     */
    public class Class95
    {
        public IList<TreeNode> GenerateTrees(int n)
        {
            if (n == 0)
                return new List<TreeNode>(0);
            var result = Generate(1, n + 1);
            return result;
        }

        private List<TreeNode> EmptyResults = new List<TreeNode>(1) { null };
        private IList<TreeNode> Generate(int i, int k)
        {
            if (i == k)
                return EmptyResults;
            var result = new List<TreeNode>();
            for (int j = i; j < k; j++)
            {
                var leftNode = Generate(i, j);
                var rightNode = Generate(j + 1, k);
                foreach (var left in leftNode)
                {
                    foreach (var right in rightNode)
                    {
                        result.Add(new TreeNode(j) { left = left, right = right });
                    }
                }
            }
            return result;
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
