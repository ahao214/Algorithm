using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1110
{
    public class Class1110
    {

        public IList<TreeNode> DelNodes(TreeNode root, int[] to_delete)
        {
            ISet<int> toDeleteSet = new HashSet<int>();
            foreach (int val in to_delete)
            {
                toDeleteSet.Add(val);
            }
            IList<TreeNode> roots = new List<TreeNode>();
            DFS(root, true, toDeleteSet, roots);
            return roots;
        }

        public TreeNode DFS(TreeNode node, bool isRoot, ISet<int> toDeleteSet, IList<TreeNode> roots)
        {
            if (node == null)
            {
                return null;
            }
            bool deleted = toDeleteSet.Contains(node.val);
            node.left = DFS(node.left, deleted, toDeleteSet, roots);
            node.right = DFS(node.right, deleted, toDeleteSet, roots);
            if (deleted)
            {
                return null;
            }
            else
            {
                if (isRoot)
                {
                    roots.Add(node);
                }
                return node;
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
