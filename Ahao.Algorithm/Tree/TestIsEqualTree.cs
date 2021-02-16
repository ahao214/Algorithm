using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 判断两颗二叉树是否相等
    /// </summary>
    public class TestIsEqualTree
    {
        /// <summary>
        /// 方法功能：判断两个二叉树是否相等
        /// 参数：root1与root2分别为两个二叉树的根结点       
        /// </summary>
        /// <param name="root1"></param>
        /// <param name="root2"></param>
        /// <returns></returns>
        public static bool IsEqual(BiTNode root1, BiTNode root2)
        {
            if (root1 == null && root2 == null)
            {
                return true;
            }

            if (root1 == null && root2 != null)
            {
                return false;
            }

            if (root1 != null && root2 == null)
            {
                return false;
            }

            if (root1.Data == root2.Data)
            {
                return IsEqual(root1.Lchild, root2.Lchild) && IsEqual(root1.Rchild, root2.Rchild);
            }
            else
            {
                return false;
            }
        }


        /// <summary>
        /// 方法功能：构造二叉树
        /// 返回值：返回新构造的二叉树的根结点
        /// </summary>
        /// <returns></returns>
        public static BiTNode constructTree(int i, int j, int x, int y)
        {
            BiTNode root = new BiTNode();
            BiTNode node1 = new BiTNode();
            BiTNode node2 = new BiTNode();
            BiTNode node3 = new BiTNode();
            BiTNode node4 = new BiTNode();
            root.Data = i;
            node1.Data = j;
            node2.Data = x;
            node3.Data = y;
            node4.Data = 9;
            root.Lchild = node1;
            root.Rchild = node2;
            node1.Lchild = node3;
            node1.Rchild = node4;
            node2.Lchild = node2.Rchild = node3.Lchild = node3.Rchild = node4.Lchild = node4.Rchild = null;
            return root;
        }
    }
}
