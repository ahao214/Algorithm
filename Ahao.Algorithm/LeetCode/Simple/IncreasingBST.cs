using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 897. 递增顺序搜索树
    /// </summary>
    public class IncreasingBST
    {
        public TreeNodes Method(TreeNodes root)
        {
            List<int> lst = new List<int>();
            Stack<TreeNodes> stack = new Stack<TreeNodes>();
            LeftOrder(root, lst);
            TreeNodes newTree = new TreeNodes(lst[0]);
            TreeNodes tmp = newTree;
            for (int i = 1; i < lst.Count; i++)
            {
                tmp.right = new TreeNodes(lst[i]);
                tmp = tmp.right;
            }
            return newTree;
        }


        private void LeftOrder(TreeNodes root, List<int> lst)
        {
            if (root != null)
            {
                LeftOrder(root.left, lst);
                lst.Add(root.val);
                LeftOrder(root.right, lst);
            }
        }

        /// <summary>
        /// 方法功能：构造二叉树
        /// 返回值：返回新构造的二叉树的根结点
        /// </summary>
        /// <returns></returns>
        public static TreeNodes constructTree()
        {
            TreeNodes root = new TreeNodes();
            TreeNodes node1 = new TreeNodes();
            TreeNodes node2 = new TreeNodes();
            TreeNodes node3 = new TreeNodes();
            TreeNodes node4 = new TreeNodes();
            TreeNodes node5 = new TreeNodes();
            TreeNodes node6 = new TreeNodes();
            TreeNodes node7 = new TreeNodes();
            TreeNodes node8 = new TreeNodes();
            root.val = 5;
            node1.val = 3;
            node2.val = 6;
            node3.val = 2;
            node4.val = 4;
            node5.val = 8;
            node6.val = 1;
            node7.val = 7;
            node8.val = 9;
            root.left = node1;
            root.right = node2;
            node1.left = node3;
            node1.right = node4;
            node3.left = node6;
            node2.right = node5;
            node5.left = node7;
            node5.right = node8;
            node3.right = node4.left = node4.right = node2.left = null;

            return root;
        }

    }

    public class TreeNodes
    {
        public int val;
        public TreeNodes left;
        public TreeNodes right;
        public TreeNodes(int val = 0, TreeNodes left = null, TreeNodes right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

}
