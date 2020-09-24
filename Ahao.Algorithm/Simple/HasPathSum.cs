using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 112.路径总和
    /// </summary>
    public class HasPathSum
    {
        public bool Method(TreeNode root, int sum)
        {
            if (root == null)
            {
                return false;
            }            
            if (root.left == null && root.right == null)
            {
                return root.val == sum;
            }
            sum -= root.val;
            if (Method(root.left, sum) || Method(root.right, sum))
            {
                return true;
            }
            return false;
        }


        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int x) { val = x; }
        }
    }
}
