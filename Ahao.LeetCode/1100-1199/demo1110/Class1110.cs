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


        bool[] toDelete = new bool[1001];
        List<TreeNode> res = new List<TreeNode>();
        public IList<TreeNode> DelNodes2(TreeNode root, int[] to_delete)
        {
            foreach (var item in to_delete)
            {
                toDelete[item] = true;
            }
            if (DFS2(root) != null)
            {
                res.Add(root);
            }
            return res;
        }

        private TreeNode DFS2(TreeNode root)
        {
            if (root == null)
            {
                return null;
            }
            root.left = DFS2(root.left);
            root.right = DFS2(root.right);
            if (toDelete[root.val])
            {
                if (root.left != null)
                {
                    res.Add(root.left);
                }
                if (root.right != null)
                {
                    res.Add(root.right);
                }
                return null;
            }
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
