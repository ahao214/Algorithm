using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.UI;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 复制二叉树
    /// </summary>
    public class TestCopyTree
    {
        public static BiTNode createDupTree(BiTNode root)
        {
            if (root == null)
            {
                return null;
            }
            //二叉树根结点
            BiTNode dupTreee = new BiTNode();
            dupTreee.Data = root.Data;
            //复制左子树
            dupTreee.Lchild = createDupTree(root.Lchild);
            //复制右子树
            dupTreee.Rchild = createDupTree(root.Rchild);
            return dupTreee;
        }

        public static BiTNode constructTree()
        {
            BiTNode root = new BiTNode();
            BiTNode node1 = new BiTNode();
            BiTNode node2 = new BiTNode();
            BiTNode node3 = new BiTNode();
            BiTNode node4 = new BiTNode();
            root.Data = 6;
            node1.Data = 3;
            node2.Data = -7;
            node3.Data = -1;
            node4.Data = 9;
            root.Lchild = node1;
            root.Rchild = node2;
            node1.Lchild = node3;
            node1.Rchild = node4;
            node2.Lchild = node2.Rchild = node3.Lchild = node3.Rchild = node4.Lchild = node4.Rchild = null;
            return root;
        }

        public static void printTreeMidOrder(BiTNode root)
        {
            if (root == null)
            {
                return;
            }
            //遍历root结点的左子树
            if (root.Lchild != null)
            {
                printTreeMidOrder(root.Lchild);
            }
            //遍历root结点
            Console.Write(root.Data + " ");
            //遍历root结点的右子树
            if (root.Rchild != null)
            {
                printTreeMidOrder(root.Rchild);
            }
        }

    }
}
