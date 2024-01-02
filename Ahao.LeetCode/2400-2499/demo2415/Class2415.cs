using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2415
{
    public class Class2415
    {

        public TreeNode ReverseOddLevels(TreeNode root)
        {
            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            bool isOdd = false;
            while (queue.Count > 0)
            {
                int sz = queue.Count;
                IList<TreeNode> arr = new List<TreeNode>();
                for (int i = 0; i < sz; i++)
                {
                    TreeNode node = queue.Dequeue();
                    if (isOdd)
                    {
                        arr.Add(node);
                    }
                    if (node.left != null)
                    {
                        queue.Enqueue(node.left);
                        queue.Enqueue(node.right);
                    }
                }
                if (isOdd)
                {
                    for (int l = 0, r = sz - 1; l < r; l++, r--)
                    {
                        int temp = arr[l].val;
                        arr[l].val = arr[r].val;
                        arr[r].val = temp;
                    }
                }
                isOdd ^= true;
            }
            return root;
        }




        public TreeNode ReverseOddLevels2(TreeNode root)
        {
            DFS(root.left, root.right, true);
            return root;
        }

        public void DFS(TreeNode root1, TreeNode root2, bool isOdd)
        {
            if (root1 == null)
            {
                return;
            }
            if (isOdd)
            {
                int temp = root1.val;
                root1.val = root2.val;
                root2.val = temp;
            }
            DFS(root1.left, root2.right, !isOdd);
            DFS(root1.right, root2.left, !isOdd);
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
