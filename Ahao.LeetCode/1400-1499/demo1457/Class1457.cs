using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1457
{
    public class Class1457
    {

        public int PseudoPalindromicPaths(TreeNode root)
        {
            int[] counter = new int[10];
            return DFS(root, counter);
        }

        public int DFS(TreeNode root, int[] counter)
        {
            if (root == null)
            {
                return 0;
            }
            counter[root.val]++;
            int res = 0;
            if (root.left == null && root.right == null)
            {
                if (IsPseudoPalindrome(counter))
                {
                    res = 1;
                }
            }
            else
            {
                res = DFS(root.left, counter) + DFS(root.right, counter);
            }
            counter[root.val]--;
            return res;
        }

        public bool IsPseudoPalindrome(int[] counter)
        {
            int odd = 0;
            foreach (int value in counter)
            {
                if (value % 2 == 1)
                {
                    odd++;
                }
            }
            return odd <= 1;
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
