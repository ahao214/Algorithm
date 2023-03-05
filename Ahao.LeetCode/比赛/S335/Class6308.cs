using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛.S335
{
    /*
     6308. 二叉树中的第 K 大层和 

给你一棵二叉树的根节点 root 和一个正整数 k 。

树中的 层和 是指 同一层 上节点值的总和。

返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 -1 。

注意，如果两个节点与根节点的距离相同，则认为它们在同一层。

输入：root = [5,8,9,2,1,3,7,4,6], k = 2
输出：13
解释：树中每一层的层和分别是：
- Level 1: 5
- Level 2: 8 + 9 = 17
- Level 3: 2 + 1 + 3 + 7 = 13
- Level 4: 4 + 6 = 10
第 2 大的层和等于 13 。
     */
    class Class6308
    {
        public long KthLargestLevelSum(TreeNode root, int k)
        {
            List<long> list = new List<long>();
            Queue<TreeNode> q = new Queue<TreeNode>();
            q.Enqueue(root);
            while (q.Count > 0)
            {
                long sum = 0;
                int size = q.Count;
                for (int i = 0; i < size; i++)
                {
                    TreeNode a = q.Dequeue();
                    sum += a.val;
                    if (a.left != null)
                    {
                        q.Enqueue(a.left);
                    }
                    if (a.right != null)
                    {
                        q.Enqueue(a.right);
                    }
                }
                list.Add(sum);
            }
            long[] arr = list.ToArray();
            Array.Sort(arr);
            
            if (list.Count < k)
                return -1;
            
            return arr[arr.Length - k];
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
