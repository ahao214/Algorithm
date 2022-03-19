using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo606
{
    public class Class606
    {
        public string Tree2str(TreeNode root)
        {
            if (root == null)
                return "";
            if (root.left == null && root.right == null)
                return root.val.ToString();
            StringBuilder sb = new StringBuilder();
            if (root.right == null)
            {
                return sb.Append(root.val).Append("(").Append(Tree2str(root.left)).Append(")").ToString();
            }
            return sb.Append(root.val).Append("(").Append(Tree2str(root.left)).Append(")(").Append(Tree2str(root.right)).Append(")").ToString();
        }

        /// <summary>
        /// 迭代
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public string TreeToStr(TreeNode root)
        {
            StringBuilder ans = new StringBuilder();
            Stack<TreeNode> stk = new Stack<TreeNode>();
            stk.Push(root);
            ISet<TreeNode> visited = new HashSet<TreeNode>();
            while (stk.Count > 0)
            {
                TreeNode node = stk.Peek();
                if (!visited.Add(node))
                {
                    if (node != root)
                    {
                        ans.Append(")");
                    }
                    stk.Pop();
                }
                else
                {
                    if (node != root)
                    {
                        ans.Append("(");
                    }
                    ans.Append(node.val);
                    if (node.left == null && node.right != null)
                    {
                        ans.Append("()");
                    }
                    if (node.right != null)
                    {
                        stk.Push(node.right);
                    }
                    if (node.left != null)
                    {
                        stk.Push(node.left);
                    }
                }
            }
            return ans.ToString();
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
