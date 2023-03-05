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
            List<IList<int>> result = new List<IList<int>>();
            int count = 0;
            int maxDepth = 0;
            if (root == null)
            {
                return 0;
            }
            GetMore(root);
            ISet<int> st = new HashSet<int>();
            for (int i = 0;i < result.Count; i++)
            {
                int sum = 0;
                for (int j = 0; j < result[i].Count; j++)
                    sum += result[i][j];
                st.Add(sum);
            }
            
            int[] arr = st.ToArray();
            Array.Sort(arr);
            if (k > arr.Length)
                return -1;

            for (int i = arr.Length - 1; i >= 0; i--,k--)
            {
                if (k == 0)
                    return arr[i];
            }
            return -1;

            void GetMore(TreeNode node)
            {
                count++;
                if (count > maxDepth)
                {
                    maxDepth = count;
                    result.Add(new List<int>());
                }
                result[count - 1].Add(node.val);
                if (node.left != null)
                {
                    GetMore(node.left);
                }
                if (node.right != null)
                {
                    GetMore(node.right);
                }
                count--;
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
