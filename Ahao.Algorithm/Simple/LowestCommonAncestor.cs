using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 235. 二叉搜索树的最近公共祖先
    /// </summary>
    public class LowestCommonAncestor
    {
        //使用递归
        public TreeNode Method(TreeNode root, TreeNode p, TreeNode q)
        {
            if ((p.val < root.val) && (q.val < root.val))
            {
                return Method(root.left, p, q);
            }
            else if ((p.val > root.val) && (q.val > root.val))
            {
                return Method(root.right, p, q);
            }
            else
            {
                return root;
            }
        }

        //使用迭代
        public TreeNode Method2(TreeNode root, TreeNode p, TreeNode q)
        {
            TreeNode node = root;
            while (node != null)
            {
                if ((p.val < node.val) && (q.val < node.val))
                {
                    node = node.left;
                }
                else if ((p.val > node.val) && (q.val > node.val))
                {
                    node = node.right;
                }
                else
                {
                    break;
                }
            }
            return node;
        }

    }

    //public class TreeNode
    //{
    //    public int val;
    //    public TreeNode left;
    //    public TreeNode right;
    //    public TreeNode(int x) { val = x; }
    //}
}
