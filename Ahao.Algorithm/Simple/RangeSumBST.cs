using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 938. 二叉搜索树的范围和
    /// </summary>
    public class RangeSumBST
    {
        public int Method(TreeNodeBST root, int low, int high)
        {
            int sum = 0;
            if (root == null)
            {
                return sum;
            }
            sum = low + high;
            TreeNodeBST p;
            Queue<TreeNodeBST> queue = new Queue<TreeNodeBST>();
            queue.Enqueue(root);
            while (queue.Count() > 0)
            {
                p = queue.Dequeue();
                if (p.val > low && p.val < high)
                {
                    sum += p.val;
                }
                if (p.left != null)
                    queue.Enqueue(p.left);
                if (p.right != null)
                    queue.Enqueue(p.right);
            }
            return sum;
        }

        public class TreeNodeBST
        {
            public int val;
            public TreeNodeBST left;
            public TreeNodeBST right;
            public TreeNodeBST(int val = 0, TreeNodeBST left = null, TreeNodeBST right = null)
            {
                this.val = val;
                this.left = left;
                this.right = right;
            }
        }

    }
}
