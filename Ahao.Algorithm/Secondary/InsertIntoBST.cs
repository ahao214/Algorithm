using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 701. 二叉搜索树中的插入操作
    /// </summary>
    public class InsertIntoBST
    {
        public TreeNodeInsertIntoBST Method(TreeNodeInsertIntoBST root, int val)
        {
            if (root == null)
            {
                return new TreeNodeInsertIntoBST(val, null, null);
            }
            if (root.val <= val)
            {
                if (root.right == null)
                {
                    root.right = new TreeNodeInsertIntoBST(val, null, null);
                }
                else
                {
                    Method(root.right, val);
                }
            }
            else
            {
                if (root.left == null)
                {
                    root.left = new TreeNodeInsertIntoBST(val, null, null);
                }
                else
                {
                    Method(root.left, val);
                }
            }
            return root;
        }
    }

    public class TreeNodeInsertIntoBST
    {
        public int val;
        public TreeNodeInsertIntoBST left;
        public TreeNodeInsertIntoBST right;
        public TreeNodeInsertIntoBST(int val = 0, TreeNodeInsertIntoBST left = null, TreeNodeInsertIntoBST right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

}
