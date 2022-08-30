using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo998
{
    public class Class998
    {
        public TreeNode InsertIntoMaxTree(TreeNode root, int val)
        {
            TreeNode parent = null;
            TreeNode cur = root;
            while (cur != null)
            {
                if (val > cur.val)
                {
                    if (parent == null)
                    {
                        return new TreeNode(val, root, null);
                    }
                    TreeNode node = new TreeNode(val, cur, null);
                    parent.right = node;
                    return root;
                }
                else
                {
                    parent = cur;
                    cur = cur.right;
                }
            }
            parent.right = new TreeNode(val);
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
