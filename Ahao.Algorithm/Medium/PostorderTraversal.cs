using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 145.二叉树的后序遍历
    /// </summary>
    public class PostorderTraversal
    {
        public IList<int> Method(TreeNodePostorderTraversal root)
        {
            LinkedList<TreeNodePostorderTraversal> stack = new LinkedList<TreeNodePostorderTraversal>();
            var list = new List<int>();
            if (root == null)
            {
                return list;
            }
            stack.AddLast(root);
            while (stack.Count > 0)
            {
                TreeNodePostorderTraversal node = stack.Last();
                stack.RemoveLast();
                list.Insert(0, node.val);

                if (node.left != null)
                {
                    stack.AddLast(node.left);
                }
                if (node.right != null)
                {
                    stack.AddLast(node.right);
                }
            }

            return list;
        }
    }


    public class TreeNodePostorderTraversal
    {
        public int val;
        public TreeNodePostorderTraversal left;
        public TreeNodePostorderTraversal right;
        public TreeNodePostorderTraversal(int val = 0, TreeNodePostorderTraversal left = null, TreeNodePostorderTraversal right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

}
