using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 把一个有序整数数组放到二叉树中
    /// </summary>
    public class TestArraytotree
    {
        /// <summary>
        /// 方法功能：把有序数组转换为二叉树
        /// 输入参数：arr-数组
        /// 返回值：转换后的数的根节点
        /// </summary>
        /// <param name="arr"></param>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <returns></returns>
        public static BiTNode Arraytotree(int [] arr ,int start,int end)
        {
            BiTNode root = null;
            if(end >=start)
            {
                root = new BiTNode();
                int mid = (start + end + 1) / 2;
                //树的根节点为数组中间的元素
                root.Data = arr[mid];
                //通过递归法用左半部分数组构造root的左子树
                root.Lchild = Arraytotree(arr, start, mid - 1);
                //通过递归法用右半部分数组构造root的右子树
                root.Rchild = Arraytotree(arr, mid + 1, end);
            }
            else
            {
                root = null;
            }
            return root;
        }

        /// <summary>
        /// 用中序遍历的方式打印出二叉树结点的内容
        /// </summary>
        /// <param name="root"></param>
        public static void PrintTreeMidOrders(BiTNode root)
        {
            if(root ==null )
            {
                return;
            }
            //遍历root结点的左子树
            if(root.Lchild !=null )
            {
                PrintTreeMidOrders(root.Lchild);
            }
            //遍历root结点
            Console.Write(root.Data + " ");
            //遍历root结点的右子树
            if(root.Rchild!=null )
            {
                PrintTreeMidOrders(root.Rchild);
            }
        }
    }
}
