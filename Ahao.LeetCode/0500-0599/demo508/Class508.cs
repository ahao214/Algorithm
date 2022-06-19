using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo508
{
    public class Class508
    {

        Dictionary<int, int> cnt = new Dictionary<int, int>();
        int maxCnt = 0;

        public int[] FindFrequentTreeSum(TreeNode root)
        {
            DFS(root);
            IList<int> ans = new List<int>();
            foreach (KeyValuePair<int, int> pair in cnt)
            {
                int s = pair.Key, c = pair.Value;
                if (c == maxCnt)
                {
                    ans.Add(s);
                }
            }
            return ans.ToArray();
        }

        public int DFS(TreeNode node)
        {
            if (node == null)
            {
                return 0;
            }
            int sum = node.val + DFS(node.left) + DFS(node.right);
            if (!cnt.ContainsKey(sum))
            {
                cnt.Add(sum, 0);
            }
            maxCnt = Math.Max(maxCnt, ++cnt[sum]);
            return sum;
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
