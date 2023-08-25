using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1448
{
    public class Class1448
    {

        public int GoodNodes(TreeNode root)
        {
            return DFS(root, int.MinValue);
        }

        public int DFS(TreeNode root, int pathMax)
        {
            if (root == null)
            {
                return 0;
            }
            int res = 0;
            if (root.val >= pathMax)
            {
                res++;
                pathMax = root.val;
            }
            res += DFS(root.left, pathMax) + DFS(root.right, pathMax);
            return res;
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
