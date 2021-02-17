using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Profile;

namespace Ahao.Algorithm.Tree
{
    public class TestInOrderBSTree
    {

        public static BiTNode pHead = null; //双向链表头结点
        public static BiTNode pEnd = null;  //双向链表尾结点

        /// <summary>
        /// 方法功能：把二叉树转换为双向链表
        /// 输入参数：root-二叉树根结点
        /// </summary>
        /// <param name="root"></param>
        public static void InOrderBSTree(BiTNode root)
        {
            if (root == null)
            {
                return;
            }

            //转换root的左子树
            InOrderBSTree(root.Lchild);

            root.Lchild = pEnd; //使当前结点的左指针指向双向链表中最后一个结点
            if (pEnd == null)
            {
                //双向链表中最后一个结点的右指针指向当前结点
                pHead = root;
            }
            else
            {
                //使双向链表中最后一个结点的右指针指向当前结点
                pEnd.Rchild = root;
            }

            pEnd = root;    //将当前结点设为双向链表中最后一个结点

            //转换root的右子树
            InOrderBSTree(root.Rchild);

        }
    }
}
