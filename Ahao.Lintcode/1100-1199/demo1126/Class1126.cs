using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Lintcode._1100_1199.demo1126
{
    public class Class1126
    {
        public TreeNode mergeTrees(TreeNode t1, TreeNode t2)
        {
            if (t1 == null)
                return t2;
            if (t2 == null)
                return t1;
            TreeNode tmp = new TreeNode(t1.val + t2.val);
            tmp.left = mergeTrees(t1.left, t2.left);
            tmp.right = mergeTrees(t1.right, t2.right);
            return tmp;
        }
    }

    public class TreeNode
    {
        public int val;
        public TreeNode left, right;
        public TreeNode(int val)
        {
            this.val = val;
            this.left = this.right = null;
        }
    }
}
